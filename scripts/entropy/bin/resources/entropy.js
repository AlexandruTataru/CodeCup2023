/**
 * Created by Ludo Pulles on 2017-12-26.
 */

/*******************************************************************************
 * Entropy is the object which manages the game visualisation.
 * This part makes sure that the board transitions can be made.
 * When the board is changed, it sends the board to all its controllers.
 ******************************************************************************/

function Entropy(playerNames, moves) {
	this.playerNames = playerNames;
	this.size = 7;

	this.moves = [ "Start" ];
	this.grid = Array(this.size * this.size);
	for (var i=this.size*this.size; i-->0; ) this.grid[i] = 0;
	for (var i in moves) {
		if (i % 2 == 0) {
			this.moves.push({ pos: this.size*(moves[i].charCodeAt(0) - 65) + moves[i].charCodeAt(1) - 97, // A, a
				color: moves[i].charCodeAt(4) - 48 }); // 0
		} else {
			this.moves.push({ from: this.size*(moves[i].charCodeAt(0) - 65) + moves[i].charCodeAt(1) - 97,
				to: this.size*(moves[i].charCodeAt(2) - 65) + moves[i].charCodeAt(3) - 97 });
		}
	}

	this.isRunning = false;
	this.board = document.getElementById('game-container');
	this.moveTable = document.getElementById('move-table').children[0];

	var C = function(tag, kids, attrs) {
		var x = document.createElement(tag);
		for (i in (kids||[])) x.appendChild(kids[i]);
		if (attrs && attrs['class']) x.className = attrs['class'];
		if (attrs && attrs['text']) x.innerText = attrs['text'];
		return x;
	};

	this.cells = [];
	this.legends = [];
	this.rowsum = [];
	this.colsum = [];

	var head = [ C('th') ], cells = [];
	for (var col = 0; col < this.size; col++) {
		head.push(C('th', [], {text:String.fromCharCode(97 + col)}));
	}
	for (var row = 0; row < this.size; row++) {
		var rowcells = [ C('td', [], {text:String.fromCharCode(65 + row), class:'frow'}) ];
		for (var col = 0; col < this.size; col++) {
			var leg = C('div', [], {class:'legend'});
			var cell = C('div', [leg], {class:'empty'});
			rowcells.push(C('td', [cell]));
			this.cells.push(cell);
			this.legends.push(leg);
		}
		var rsum = C('td', [], {class:'lrow', text:'0'});
		this.rowsum.push(rsum);
		rowcells.push(rsum);
		cells.push(C('tr', rowcells));
	}

	var foot = [ C('td', [], {class:'frow'}) ];
	for (var col = 0; col < this.size; col++) {
		var cell = C('td', [], {text:'0'});
		this.colsum.push(cell);
		foot.push(cell);
	}
	foot.push(this.totsum = C('td', [], {class:'tot', text:'0'}))

	this.board.appendChild(C('table', [
		C('thead', [C('tr', head)]),
		C('tbody', cells),
		C('tfoot', [C('tr', foot)])
	]));

	this.curMove = 0;

	this.registerEvents();
	this.buildMoveTable(C, moves);
	this.updateSelectedRow();
}

// Update the rowsum, colsum cells
Entropy.prototype.updateScore = function() {
	var S = this.size, F = function(A, dom) {
		// calculate score in cells, and put the answer in dom.innerText:
		var res = 7*(S >= 7 && A[0]!=0 && A[1]!=0 && A[2]!=0 && A[0] == A[6] && A[1] == A[5] && A[2] == A[4]);
		for (var i=0; i+1 < S; i++) res += 2*(A[i]!=0 && A[i] == A[i+1]);
		for (var i=0; i+2 < S; i++) res += 3*(A[i]!=0 && A[i] == A[i+2]);
		for (var i=0; i+3 < S; i++) res += 4*(A[i]!=0 && A[i] == A[i+3] && A[i+1]!=0 && A[i+1] == A[i+2]);
		for (var i=0; i+4 < S; i++) res += 5*(A[i]!=0 && A[i] == A[i+4] && A[i+1]!=0 && A[i+1] == A[i+3]);
		for (var i=0; i+5 < S; i++) res += 6*(A[i]!=0 && A[i] == A[i+5] && A[i+1]!=0 && A[i+1] == A[i+4] && A[i+2]!=0 && A[i+2] == A[i+3]);
		dom.innerText = res;
		return res;
	};
	var tot = 0;
	for (var r = 0; r < S; r++)
		tot += F(this.grid.slice(S*r, S*(r + 1)), this.rowsum[r]);
	for (var c = 0; c < S; c++) {
		var cells = [];
		for (var p = c; p < S*S; p += S) cells.push(this.grid[p]);
		tot += F(cells, this.colsum[c]);
	}
	this.totsum.innerText = tot;
}

// returns whether the move has been processed
Entropy.prototype.setMove = function(move) {
	if (move < 0 || move >= this.moves.length) return false;
	if (move == this.curMove) return true;
	var self = this;
	processMove = function(m, mv_nr, add) {
		if (mv_nr % 2 == 0) {
			self.cells[m.pos].className = add ? ("stone stone" + m.color) : "empty";
			self.legends[m.pos].textContent = add ? m.color : "";
			self.grid[m.pos] = add ? m.color : 0;
		} else if (m.from != m.to) {
			var fr = add ? m.from : m.to, to = add ? m.to : m.from;
			self.cells[to].className = self.cells[fr].className;
			self.cells[fr].className = "";
			self.legends[to].textContent = self.legends[fr].textContent;
			self.legends[fr].textContent = "";
			self.grid[to] = self.grid[fr];
			self.grid[fr] = 0;
		}
	};

	while (this.curMove > move) {
		// change a move back.
		// undo this.curMove
		var cur = this.moves[this.curMove--];
		processMove(cur, this.curMove, false);
	}
	while (this.curMove < move) {
		// process this.curMove
		var cur = this.moves[++this.curMove];
		processMove(cur, this.curMove-1, true);
	}

	this.updateScore();
	this.updateSelectedRow();
	return true;
};

// -----------------------------------------------------------------------------
// Event handlers:
// -----------------------------------------------------------------------------

Entropy.prototype.setRunning = function(running) {
	if (this.isRunning == running) return;

	this.isRunning = running;
	this.playPause.innerText = running ? 'Pause' : 'Play';

	var self = this, run = function() {
		if (!self.isRunning) return;

		if (self.setMove(self.curMove + 1)) {
			setTimeout(run, 500);
		} else {
			// last move has been reached.
			self.setRunning(false);
		}
	}
	if (this.isRunning) run();
}

Entropy.prototype.prevMove = function() { this.setRunning(false); this.setMove(this.curMove - 1); };
Entropy.prototype.nextMove = function() { this.setRunning(false); this.setMove(this.curMove + 1); };

Entropy.prototype.registerEvents = function() {
	this.playPause = document.getElementById('play-pause');

	var self = this;
	document.getElementById('first').onclick = function() { self.setRunning(false); self.setMove(0); };
	document.getElementById('last').onclick = function() { self.setRunning(false); self.setMove(self.moves.length - 1); };
	document.getElementById('prev').onclick = function() { self.prevMove(); };
	document.getElementById('next').onclick = function() { self.nextMove(); };
	this.playPause.onclick = function() { self.setRunning(!self.isRunning); };
};


Entropy.prototype.buildMoveTable = function(C, moves) {
	var self = this, players = [ "Chaos", "Order" ];

	var head = [ C('th') ];
	for (var i in players) {
		// cut-off on more than 20 characters in the name
		var playerName = players[i];
		if (this.playerNames) {
			var name = this.playerNames[i];
			if (name.length > 20) name = name.slice(0, 17) + "...";
			playerName = name + " as " + playerName;
		}
		head.push(C('th', [], {text:playerName}));
	}

	var rows = [];
	for (var i = 0; i <= moves.length; i++) {
		var row = [ C('th', [], {text:i+'.'}) ];
		var curp = i == 0 ? 0 : (i - 1) % 2;
		for (var j in players) {
			if (j == curp) row.push(C('td', [], {text: i ? moves[i-1] : "Start"}));
			else row.push(C('td'));
		}
		var tr = C('tr', row, {class: i%2 ? 'zebra' : ''});
		tr.onclick = (function(move) { return function() { self.setMove(move); } })(i);
		rows.push(tr);
	}

	this.moveTableBody = C('tbody', rows);
	this.moveTable.onkeydown = function(event) {
		if (event.keyCode == 38 || event.keyCode == 37) {
			self.prevMove();
		} else if (event.keyCode == 40 || event.keyCode == 39) {
			self.nextMove();
		} else {
			return;
		}
		event.preventDefault();
		event.stopImmediatePropagation();
	};

	this.moveTable.appendChild(C('table', [C('thead', [C('tr', head)]), this.moveTableBody]));
};

Entropy.prototype.updateSelectedRow = function() {
	var lastCurMove = document.getElementById('cur-move');
	var tbl = this.moveTable;

	// reset the id.
	if (lastCurMove) lastCurMove.id = '';

	if (this.curMove >= 0) {
		var curRow = this.moveTableBody.children[this.curMove];
		curRow.id = 'cur-move';

		var topCoord = curRow.offsetTop;
		var bottomCoord = curRow.offsetTop + curRow.offsetHeight - tbl.offsetHeight;
		if (tbl.scrollTop < bottomCoord) {
			tbl.scrollTop = bottomCoord;
		} else if (tbl.scrollTop > topCoord) {
			tbl.scrollTop = topCoord;
		}
	} else {
		tbl.scrollTop = 0;
	}
};

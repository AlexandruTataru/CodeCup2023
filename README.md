### CodeCup2023
Contestant for the [2023 CodeCup challenge](https://www.codecup.nl/competition.php?comp=294), playing the game of [Entropy](https://www.codecup.nl/entropy/rules.php).

### Implementations

#### Implementation 1
This is the simples implementation possible.
Order places the drawn color in the first free cell it finds from top-left to bottom-right and Chaos does not move any piece.

M: GAME 1 = bot <> player2
M: RESULT = 186 - 214 (game marks) PLAYER_1:_LOSE;_PLAYER_2:_WIN
M: GAME 2 = player2 <> bot
M: RESULT = 268 - 132 (game marks) PLAYER_1:_WIN;_PLAYER_2:_LOSE
 52721  player3
 47683  player2
 33713  player1
  9883  bot

#### Implementation 2
One step up is Order placing the drawn color in a random free cell on the board.

M: GAME 1 = bot <> player2
M: RESULT = 141 - 259 (game marks) PLAYER_1:_LOSE;_PLAYER_2:_WIN
M: GAME 2 = player2 <> bot
M: RESULT = 270 - 130 (game marks) PLAYER_1:_WIN;_PLAYER_2:_LOSE
 52866  player3
 47641  player2
 33812  player1
  9681  bot

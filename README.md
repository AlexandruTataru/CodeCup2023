### CodeCup2023
Contestant for the [2023 CodeCup challenge](https://www.codecup.nl/competition.php?comp=294), playing the game of [Entropy](https://www.codecup.nl/entropy/rules.php).

### Implementations

#### Implementation 1
Order places the drawn color in the first free cell it finds from top-left to bottom-right.
Chaos does not move any piece.

```
M: GAME 1 = bot <> player2
M: RESULT = 186 - 214 (game marks) PLAYER_1:_LOSE;_PLAYER_2:_WIN
M: GAME 2 = player2 <> bot
M: RESULT = 268 - 132 (game marks) PLAYER_1:_WIN;_PLAYER_2:_LOSE
 52721  player3
 47683  player2
 33713  player1
  9883  bot
```

#### Implementation 2
Order places the drawn color in a random free cell on the board.
Chaos does not move any piece.

Most likely the caiaio test players can adapt to this strategy with ease and obtain close to optimal performance just like the Implementation 1 scenario.

```
M: GAME 1 = bot <> player2
M: RESULT = 141 - 259 (game marks) PLAYER_1:_LOSE;_PLAYER_2:_WIN
M: GAME 2 = player2 <> bot
M: RESULT = 270 - 130 (game marks) PLAYER_1:_WIN;_PLAYER_2:_LOSE
 52866  player3
 47641  player2          
 33812  player1
  9681  bot
```

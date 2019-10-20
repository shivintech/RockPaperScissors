# Paper, Scissors, Rock

Paper, Scissors, Rock is an interactive two player game made using C.

## UC fun kit setup

In order to ready the fun kit for gameplay it must first be reset and plugged in (Note that the fun kit will need to be reset before the game is run each time not just at setup). To plug the fun kit in
first the non usb end of the given cord must be inserted into the slot at the top of the fun kit. Next the other end must be inserted into the usb slot of a suitable computer or laptop. A green light on the fun kit
will light up to indicate that it has been plugged in correctly. If the light doesn't turn on check that the cables have been inserted correctly before using a different usb slot and or computer/laptop. To reset the
fun kit the button S2 must be pressed (This button is on the right side of the fun kit above the navswitch when it is held upright).

## Running the game
First, the drivers for the UC fun kit need to be installed do this by opening terminal and enter the command
```bash
git clone https://eng-git.canterbury.ac.nz/rmc84/ence260-ucfk4.git
```
Next change the current directory to be in the assignment folder by entering the commands
```bash
cd ence260-ucfk4.git/
```
and
```bash
cd assignment/
```
Next download the game files into the assignment folder using the command
```bash
git clone https://eng-git.canterbury.ac.nz/ence260-2019/group239.git
```
Next change directory into the group239 folder using the command
```bash
cd group239/
```
Finally run the game using the command
```bash
make program
```

## Game rules
The rules of the game are simple. The first player to tally three wins is the overall victor. To gain a win the character that you select must beat the character that the other user selects. Where paper beats rock, rock beats scissors and scissors beats paper.

## Playing the game
After the start screen has ended the user is presented with a single character P. The character can use the navswitch (moving it up or down) to cycle through their options. The player has three characters to choose from P, S and R which correspond to paper, scissors and rock. To confirm their selection the user can click down on the navswitch. The other user will have a blue LED on their board light up and signifying that they have received the opponents selection. Once both players have confirmed their selections the result of the round will be displayed, after which the current score of each player will be displayed. The navswitch can be clicked down again to restart the next round. Once one player has reached three points the final scores will be displayed. After which the game ends.

## Authors
Shivin Gaba, Anzac Morel

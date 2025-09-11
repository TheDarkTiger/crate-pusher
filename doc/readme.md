Well, nothing much to say here.

The game is simple, and so is the algo.
The racks are stored in memory in an array, the ones on the right of the screen stored "in reverse".
This simplifies the code.

When an interraction is needed with a rack, the correct rack is selected by the Y position of Kate and the direction she is facing.
4 spaces per rack, so in memory it's like:
 0  1  2  3   7  6  5  4
 8  9 10 11  15 14 13 12
and so on.

Then, the position on the rack is checked, from out to in, to always grab/put the last postition.

Trivia:
Kate was the defunct cat of my sibling.
I named the crate mover like this for the resemblance with "crate", and as an hommage for this nice feline.
RIP, you were a good cat.

PS:
Sorry if it's not clear, it's awefully late.
I hope the code will be clear enough.

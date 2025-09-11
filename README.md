# CRATE PUSHER

![Game cover](https://github.com/TheDarkTiger/crate-pusher/blob/master/doc/cover.png?raw=true)  
A small GB arcade game for the ["GB compo 2025"](https://itch.io/jam/gbcompo25)

-----

![Game screenshot](https://github.com/TheDarkTiger/crate-pusher/blob/master/doc/screen_01.png?raw=true)

## About the game
In this game, you are Kate, the crate pusher!  
Your job is to move the crates by group for it to be send to...  
Well, you don't really know where, but all that maters is that it's not in your storage place anymore.

How to play on real hardware:
- Arrows to move Kate
- A to pick/put crate
- B to reset the level or go to the next (if finished)

Runs on BGB and real hardware (DMG and CGB). Should run on "anything", this game is very simple).

-----
The game is very unfinished at the moment, but things will come!  
For now, the last level have two "cat crates" (you will understand when you are there).  
You can finish it (hopefuly = P) but there is nothing more after that.


For more info about the gamecompo version, check out the [GBCompo2025 branch](https://github.com/TheDarkTiger/crate-pusher/tree/GBCompo2025)!


![Game screenshot](https://github.com/TheDarkTiger/crate-pusher/blob/master/doc/screen_02.png?raw=true)

## How to compile
First of all, I coded this game using Windows7 (I know, I know...) and the "build.bat".  
So, yeah, you will need to change a few things in different files to make it work for you...
- At very least, you will need to change the "CC" to indicate where GBDK is.
- You probably will need to make the "build" and "bin" folders yourself too.
- You need to change the "run" and "info" too if you need that
- The makefile should work, but no garantees (I reuse one from an other project and didn't used it)

I used gbdk-4.3.0 for the developpement, so if you use it, you _should_ have the same ROM as the one distributed here.  
No guarantees tho, when you see on what I develop and how obsolete it is, you can understand why I'm cautious.

Yes, there is a bug!
If you restart the level while holding a crate, you keep it in the new level...
And yes, if you do it "correctly", you can finish the game while holding a crate

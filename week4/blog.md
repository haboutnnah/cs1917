Similar to last week, I walked to Hornsby. Apparently it's faster, possibly due to the quality timetable changes that have occurred due to StationLink. At least we might have fast metro trains from Epping to Chatswood after it's done -- I saw they've already put up the blue circle containing a capital 'M' outside Macquarie University station, perhaps indicating it will be be complete some time soon? 


## Teamwork

Jordan and I worked on cleaning up the (abysmal) code that decides if a point is inside a triangle. This will be further elaborated on later in *Artisanship*. We also changed a 3x3 Windows Bitmap file to a 4x4 one (with a neat-o hex editor that lets you colour code stuff for easier remembering later!). Finally, we did the 'explore memory' challenge, where we looked at the memory assigned to each variable type on my Macbook Air, but the results should be consistent across all AMD64-IA32 / x64-86 platforms, and some (like the `int` and `char` types) may even be the same on IA32. 


## Time Management

I finished all assignments and lectures on time. We haven't got any lecture notes yet.

### Assignments

| Title                                       | Completed        | Date Submitted | Date Due   |
|---------------------------------------------|------------------|----------------|------------|
| Lecture09 Quiz                              | True             | 2019-03-03     | 2019-03-08 |
| Lecture10 Quiz                              | True             | 2019-03-03     | 2019-03-08 |
| Lecture11 Quiz                              | True             | 2019-03-03     | 2019-03-08 |
| Sort 3 Numbers                              | True             | 2019-03-03     | 2019-03-08 |
| You are Awesome!                            | True             | 2019-03-03     | 2019-03-08 |
| Abstract Art                                | True             | 2019-03-03     | 2019-03-08 |
| Create a 3x3 OX board image                 | True             | 2019-03-03     | 2019-03-08 |
| Assignment 1: Doomsday                      | True             | N/A            | 2019-03-08 |
| Module02 Tutorial-Lab                       | True             | N/A            | 2019-03-08 |
| TutLab: Confusing Code Makeover             | True             | N/A            | 2019-03-08 |
| TutLab: BMP 3 to 4                          | True             | N/A            | 2019-03-08 |
| TutLab: Explore Memory                      | True             | N/A            | 2019-03-08 |
| Mini-resume TIME MANAGEMENT                 | True             | 2019-03-06     | 2019-03-08 |
| Reflection and give blog feedback - Module2 | True             | N/A            | 2019-03-08 |
| Script kiddie                               | False [Optional] | N/A            | 2019-03-08 |
| 4004 Busy Beaver                            | False [Optional] | N/A            | 2019-03-08 |
| 4004 Quine                                  | False [Optional] | N/A            | 2019-03-08 |
| Less Than or Equal To                       | False [Optional] | N/A            | 2019-03-08 |

### Lecture Notes


#### Lecture 13: Functions (part 2)

* Compartmentalise as much as possible

#### Lecture 14: Bitmap Images

* You can use Wikipedia for finding the file structure of a BMP file
* 24 bit images == 8 bits of [red, green, blue].

#### Lecture 15: Addresses &pointers

* & gives the address of a pointer
* \* gives the item inside a pointer
* You can #include a local header file using `#include "file.h"`
* `scanf` et al. have side effects -- this is bad.

#### Lecture 16: Testing

* To test, `void test{functionName} (void)`
* Do a bunch of assertions: `assert (functionName(inp) == expectedOutput)`

#### Lecture 17: Repetition

* Don't repeat yourself
* Abstract away in to functions

#### Lecture 18: Replication

* Three common mistakes in loops:
*  Initialisation -- `i = 0`
*  Progression -- `i++`
*  Termination -- `i < 5`
* If `i` initialises to `0`, termination should be `<`
* If it initialises to a non-zero value, it should terminate with `<=`
* `scanf("%c", character)` if looped will loop through each character.

#### Lecture 19: Redundancy

* Try not to use side effects because they're hard to test
* Mixing `if`, `while` allows for very complex programs.

#### Lecture 20: Functions and Frames

* Stack frames store the context
* Can be attacked by modifying where to `jmp` to.

#### Lecture 20.5: 

* Literally just a section of *The Simpsons*

## Something Awesome

I worked on adding the instructions for the 8005 to my compiler, which wasn't hard. As I had extra time, I added better functionality regarding `mov`s (which I discovered was a bug when I used a ton for *You are Awesome!*).

## Craftsmanship

Jordan and I were able to clean up the code in the confusing code makeover challenge by 

* Fixing indentation to follow the course style guide (4 sp).
* Using constants instead of magic numbers
* Renaming variables to be more specific/clear
* Adding a test function to test hardcoded inputs. 
* Removing returns in if statements.
* Removed multiple returns

I also followed the style guide in all my own code, even the parts where you can't break out of a loop (I'm getting used to it now). I even commented all my asm for the microprocessors.

For *Doomsday*, I overengineered it a lot, but I did make discrete and reusable functions, such as daysInMonth (which I definitely didn't need). Using functions did make it more readable, but possibly a bit slower.

---

Overall, this week was interesting. The lectures still didn't have that much new stuff to me but trying to crack *Doomsday* was fun. Hex editors aren't as bad as I thought they would be.

As I was walking toward Waitara train station, doubt began to set in. Is this course right for me? Am I going to regret choosing x86 assembly as my something awesome? Is it frowned upon to arrive at 3 p.m. when the tute starts at 4? 

I still have no answers to any of these questions.

I mentioned to a couple of friends that I would be in Hornsby, but due to my top-tier time management, I only told them at 3:10, after they had left. At least this question won't be an issue next time. 

The assembly question will only be answered in due time.

## Teamwork

In the first tutorial, we did two teamwork activities. 

First, we attempted to estimate how many pieces of bread would fit in the room we were in. We started by measuring the room with a metre long ruler. After remembering Richard's advice of having something verifiable, we tried picturing the amount of loaves of bread in a desktop computer, and then how many of those in the server in the room, and then how many of those were in the room. The mathematical method returned half of what the other did, though.

The second activity was when we listed how we got to the tutorial, but collaboratively as a group of three, and in five steps exactly. We were then instructed to expand step three in to five more steps, and compare with the other group present. This was amusing -- we had to try and break down "cross road" in to five steps.

Pictured: the team for the travel exercise.

![](https://cdn.discordapp.com/attachments/547666017141129218/548425414012567563/image0.jpg)


## Time Management

Well, I finished all of this week's assignments last week, so that's dealt with.

Here's a neat table, with all dates in ISO 8601 format:

| Title                                       | Completed         | Date Submitted | Date Due   |
|---------------------------------------------|-------------------|----------------|------------|
| BrainTrain: Toast Estimation                | True              | 2019-02-17     | 2019-02-22 |
| BrainTrain: Player Piano                    | True              | 2019-02-17     | 2019-02-27 |
| BrainTrain: Recipe Confusion                | True              | 2019-02-17     | 2019-02-27 |
| Microprocessors: 4001 - Overview            | True              | 2019-02-17     | 2019-02-27 |
| Microprocessors: 4001 - "Pi"                | True              | 2019-02-17     | 2019-02-27 |
| Microprocessors: 4001 - "Tracing a Program" | True              | 2019-02-17     | 2019-02-27 |
| Microprocessors: 4003 - Overview            | True              | 2019-02-17     | 2019-02-27 |
| Microprocessors: 4003 - "Add"               | True              | 2019-02-17     | 2019-02-27 |
| Coding: My First C Program                  | True              | 2019-02-17     | 2019-02-27 |
| General: Blog blog blog!                    | True              | 2019-02-17     | 2019-02-27 |
| General: Week 0 Feedback                    | True              | 2019-02-17     | 2019-02-27 |
| Revision and Challenges                     | True              | 2019-02-17     | 2019-02-27 |
| Microprocessors: 4001 - "Big Piece of Pie"  | False \[Optional]              |  N/A     | 2019-02-27 |
| Microprocessors: 4003 - "Subtract"          | True | 2019-02-17           | 2019-02-27 |


### Lecture Notes

I also finished the lectures for last week, last week. 

I had already started next week's, and so I have written short summaries of what I learned.

#### Lecture 6: Two Big Ideas

* Learned about #define, which replaces every time an identifier is used with a constant (and screws with compiler warnings :( )

#### Lecture 7: Functions

* Random functions aren't functions
* What to break the doomsday assignment in to: year % 4 for leaps, %100 for not and then % 400 for adding again. The dooms day shifts one each year. 7/11, 11/7, 9/5, 5/9 are dooms days along side the nth of the nth month.

#### Lecture 8: Doomsday

* Not watched yet.


## Something Awesome

I am continuing in my quest to learn x86 assembly. 

I may regret this, given the official manual is 4898 pages.

![Picture of manual](https://i.imgur.com/lx0wZrO.png)

As a way to dip my feet in the water, I'll start with *Computer Systems: A Programmer's Perspective*. On one hand, it's much much much more digestible to us mere mortals, on the other it's by Pearson. Thankfully, a .pdf is available online so I don't have to use the battery guzzling web UI of their normal textbooks.

In things I did this week, I added support for the 4004 in my assembler.

Here's some code snippets:

**Subtracting rbx from rax**

![](https://i.imgur.com/O71wU8l.png)

**Copying from one register to another**

![](https://i.imgur.com/2z7699w.png)

and, now for my everlasting weakness,

**Jumps**

![](https://i.imgur.com/pBFycNK.png)


What this all means is this code (spoiler for the activity *if*, don't look if not done):

![](https://i.imgur.com/sWrrl4X.png)

Turns in to this:

![](https://i.imgur.com/32YKtj9.png)

**Yay!**

This means I can add comments to my 4xxx code, which leads in to . . . 

## Artisanship

Structured programming feels *weird*. It feels weird not being able to `break` from a function. It feels weird not being able to `return` from an if.

But I'm trying.

I'm returning from the end of my `process_instruction` function, something I've never done before. I normally return from inside 4.5 million if statements that have accumulated over time due to bad maintenance of the code.

But this does make it easier.

I question performance, still, but I suppose it's a trade-off for predictability.

For instance:

![](https://i.imgur.com/7eOf3e0.png)

Where I would normally do

![](https://i.imgur.com/eygpLVw.png)

No prizes for finding out which one is more readable.

Another thing you might see in that is descriptive variable names. Because me-in-2-days won't be able to read "machine_code.append(7)" and think, "ah yes this prints the value in rax".


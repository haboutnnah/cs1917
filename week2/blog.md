# Blog After Week 0

After racing to Waitara train station and getting on the correct train, I stayed on the train for an hour and then got off at central. I then proceeded to wander the catacombs that is central station and got on a bus packed to the brim. Thanks to Google Maps draining my phone battery, I got off at the right bus stop and waddled through the crowd that is UNSW in open week to the Law building. I stumbled in, to be greeted by a sea of unfamiliar faces punctuated with the occasional NCSS 2019 student. We then all poured through the lecture hall door, being given a wingding. Mine was a keyboard. I then walked around the lecture hall trying to find a seat near someone familiar. After this is a bit of a blur, as the lecture we saw there has blended with the lectures we saw at home, but no one will ever forget Hayden's majestic *Some Doge* T-shirt.

(To all those who say that they can't balance school and HS1917, I propose writing your blog posts in a way that would make your English Advanced/etc teacher proud :)

We all had pizza, and to my surprise, there was vegan pizza. The students then followed their tutors to the CSE labs, where we all changed our passwords like good digital citizen and then went home.

The next day, not satisfied with the workspace I will use for exams, I wanted to make it as close to my home development station as possible:

![Workspace, riced.](https://i.imgur.com/Vk1uCNk.png)

On the fifteenth, I was able to watch the lectures for a short period of time before they were hidden from us. Despite this, I still had the links, and so I shared them with everyone else (below), and watched them myself at school lunches and at home.

![Links to the videos.](https://i.imgur.com/vOwVJWB.png)

On the discord server, Ethan shared that you can get to the exercises by clicking they grey area of the progress bar.

I saw that we had to write assembly for the 4001 and 4003, and given I wanted my *Something Awesome* to be learning x86 assembly, I thought that making an asm to machine code compiler for these chips would be a neat idea, and I made one. In terms of craftsmanship, I tried much harder than I normally do to make structured code. Obviously, some times I did slip (it seems so much more wasteful in terms of CPU cycles!), I did try super hard. I tried to use exceptions properly and functions where possible.

Here's some code:

```py
    if multibyte:
        if instruction == 'add':
            # Manipulate the correct register
            if secondbyte == 'rax':
                for i in range(int(thirdbyte)):
                    machine_code.append(1)
            elif secondbyte == 'rbx':
                for i in range(int(thirdbyte)):
                    machine_code.append(3)
```

`jmp` and `jle` were, by far, the most difficult parts, given I wanted to be able to reference source code line values, but I perservered through it and figured it out. I mostly did this by having a shower and the last 4 productive brain cells in my head must have figured out the hacky hack that would work.

Outside of the course, something interesting that happened was I was at the [UN Youth Young Leaders Summit](https://unyouth.org.au/event/young-leaders-summit/), and saw how abstraction can be applied to so many more things. Despite obviously not being the point of the event, we explored climate change, and its interesting how you can view it differently with different viewpoints, with different things abstracted away and different things enhanced.

In the spirit of open source, I have also decided to release all the code I'm going to make in this course under the GPLv3. Although no one will use it, it's the principle that counts.

-- Hannah Ivy <contact@hannahi.com> 2019-02-17

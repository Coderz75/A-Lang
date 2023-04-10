<h1><a href = "https://coderz75.github.io/A-Lang/">A-Lang</a></h1>
Asian Language

<img src="img/logo.jpg"
     alt="A-Lang logo"
     style="text-align: center; width: 500px;" />


A-lang is held underneath the [GNU General Public liscense](./LICENSE)

A-lang is a project made for fun to play around with a parser, and just to learn more about coding

```py
say "Welcome to alang!"
```

- [Features](#feature)
- [The basics](#basic)
- [File I/O](#file)
- [Numbers](#num)
- [Concatination](#conc)
- [Cross-Compatibility](#cross)
- [Running it](#run
)
<h2 id = "feature">Features:</h2>

- Effecient - Asians must be the first to finish everything 
- No numbers - Asians don't need a computer to do math for them
- No imports - Asians don't need somebody's elses help to be the best
- Nearly no compiler errors - As an Asian, we expect that your project is error free first try. Even with an error, we will run your code, and the output will be very wierd. If something is completely wrong, we will just shut the program with a: <b>FAIL</b>
- Compatible - Our program is compatible with python, with a catch. We only do python one liners (because otherwise it would be too easy)
- No Variables - Back in my day we had to make minecraft with NO COMPUTER MEMORY

<h2 id = "basic">The basics</h2>

```py
#Note, comments have to be on a different line
say "Hello" # say "E"
#output: Hello
#        E

say "Hello" 
# say "E"
# Output: Hello
```

Lets start with the basics. We got: `say` and `req`, alang's equivelent for python's print() and input()

They both look at the token after it, and uses that for output
```py
say "Hello!"
# Output: "Hello"

req "Enter something: "
# output: Enter something: 
# Then user can input
```

Makes Sense, right?

If statements are a little more complicated. Since there are no [numbers](#num) in alang, the two tokens are: `is` and `not` to compare. To end an if, you must use the `endif` token, otherwise some wierd stuff may happen

```py
if "Hello" is "Hello"
    say "Hello"
endif
# Output: Hello

if "Hello" not "eeee"
    say "Hello is suprisingly not equal to eeeeee"
endif
#output: Hello is suprisingly not equal to eeeeee
```

<h2 id = "file">File I/O</h2>

Alang has a file I/O, which replaces traditional variables, so this program creates a file called e, and writes hello to it
```py
write "Hello" e
```
To access a file, you use `read` 
```py
say read e
# Reads file e, then says it
```
At the end of your program, you will end up with a file `e`, which is unprofesssional, So you can use the `delete` token to delete the file at the end of your program
```py
delete e
```

<h2 id = "num">Numbers</h2>

THERE ARE NO NUMBERS DID YOU EVEN READ THE [FEATURES](#feature)?

<h2 id = "conc">Concatination</h2>

Since there is no [numbers](#num) in Alang, we only got the concatinantion `+` symbol. To concatinate, just use the `+` symbol:
```py
write "Apple" funz
write read funz + "Banana"
#output: AppleBanana
```

<h2 id = "cross">Cross Compatibility</h2>

Alang is compatible with python (assuming it is downloaded on the host system), however, it only will run python oneliners, using the `py:` token
```py
py: print('Hi')
#Output: Hi
```

You may use the semicolon (`;`) to run multiple python "lines"
```py
py: print('Hi'); print('Bye')
#Output: Hi
#        Bye
```


I think that is it for the documentation. Good luck coding!

<h2 id = "run">Running the file</h2>

The executables are located within the [exec](./exec) folder. The best way is to use git

```bash
git clone https://github.com/Coderz75/A-Lang.git
```

Then add the exec directory to PATH.

Then you should be able to use use `asian` to run the file

```bash
asian hello.a
```
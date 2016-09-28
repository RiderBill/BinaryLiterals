2016-09-28. Bill Brinson

Someone asked a question on StackOverflow along the lines of why there isn't
a built in way to specify a binary literal, similar to the octal and hex
specifiers, 0xF00 and 0123. I hadn't heard about the C++14 standard allowing
binary literals (0b10110, or 0B10110). Yeah!

Anyway, I quickly figured out a macro solution pretty quickly. Then I thought
it would be fun to impliment a more fully vast template class for working with
binary formated integers. It's still a work in progress, hasn't gotten much
attention lately. Now that I've noticed the C++14 binary literal notation,
maybe I'll never finish this project. Or maybe I will, just for the challenge.
I learned about the new C++14 binary literals while looking into this; it seems
I learn something new everytime I try something new. Go figure. 

I haven't looked into the C++14 capability. Is there a binary format format
specifier for printf()? A format flag or member function to tell stream
objects to interpret input and format output as binary? Hmm... can't remember
needing that lately...

Anyway, this is my current snapshot. The associated unit test project is
FUBAR--I added it just before I stopped working on this project, only looked
at it long enough to break the stub code. I'll fix it if I ever get back to
this. Not a priority at the moment.
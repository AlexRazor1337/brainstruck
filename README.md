<pre>
  _               _           _                   _    
 | |             (_)         | |                 | |   
 | |__  _ __ __ _ _ _ __  ___| |_ _ __ _   _  ___| | __
 | '_ \| '__/ _` | | '_ \/ __| __| '__| | | |/ __| |/ /
 | |_) | | | (_| | | | | \__ | |_| |  | |_| | (__|   < 
 |_.__/|_|  \__,_|_|_| |_|___/\__|_|   \__,_|\___|_|\_\
                                                        
</pre>                                                                                                       
                                                                                                                                                                                                        
Brainstruck is my try at brainfuck interpreter. Written on C99 using standart libraries.

## Properties of the interpreter
- default memory size is set to 30000
- no wrapping on memory pointer(trying to use memory cells past 30000th will crash the program)
- memory values are wrapping

## How to use

1. Clone or download repository.
2. Run ```build.sh``` to compile the interpreter.

Now when you have a working interpreter you can use it in at least two ways:
- Pass brainfuck code directly to the program:  
```./brainstruck "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."```  
**Note:** when using it from the terminal, put the code in double-quotes because there are some special shell characters.  

- Load code from the file using **xargs**:  
```cat file | xargs -0 ./brainstruck```

## Versions
To make this more spicy, I've set a goal to create a few versions of this interpreter: a default one(human readable), one with minimal size of binary and one with minimal size of source file.

- Default (05/01/2021)  
Source code is 67 lines of code and 1698 bytes long. Binary is 16664 bytes in size. 
- Minimal binary (05/01/2021)  
Source code is 66 lines of code and 1607 bytes long. Binary is ~~10856~~ ~~10760~~ ~~10704~~ ~~10696~~ 10624 bytes in size  
- Minimal source (**TODO**)

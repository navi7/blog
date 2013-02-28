---
layout: post
title: "Basics of C++ and Visual Studio - part 2"
date: 2013-02-28 19:53
comments: true
categories: programming cpp basics visual_studio_2010 pointers references functions files
---

In a previous post we looked at how to start a simple project in
Visual Studio 2010 (ie. create solution and an empty project), and how
to add a single file to that project. Next, we typed and ran the
famous [hello_world](http://en.wikipedia.org/wiki/Hello_world_program)
program just to be sure everything works fine.

Here is the code again:
{% include_code program.cpp %} 

Next, we look at some basics: pointers, references, functions and files.

### Pointers
Simply put, pointers are **variables which contain address**. It just 
means that they contain a number and that number is an address in
the memory.

You **declare** the pointer using the **star** operator as in: `int *ptr`.

You **initialize** the pointer using the **address_of** operator 
as in: `ptr = &var`.  
The `&` gets the address of a variable `var`.

So, when you want to access the information in memory pointed to 
by `ptr`, you have to **dereference** it: `*ptr`. Now the *star* `*` 
means: go *to that address and fetch what's there*.

{% blockquote %}
Notice the double usage of the *
When declaring it means declare the pointer variable, but when 
using in an expression it means "go fetch"!
{% endblockquote %}

#### A picture is worth 1000 words:
<div class="mxgraph" style="position:relative;overflow:hidden;width:900px;height:316px;"><div style="width:1px;height:1px;overflow:hidden;">1Zffb5swEMf/mjw2MjYYeFxZs71MmtRJ2x4pOMSqwciYNOlfP1ObH8YJzbS02/IQ2V/Dcfe58xlWKCkPn0Ra777wnLAVBPlhhT6uIIwAUP+dcJwJhaC5ljwjtDQnjSVJzpmktS1mvKpIJi1ty5ltrE4L4gj3Wcpc9TvN5c44B/Gofya02PWP8XCsVxp57G3kZJu2TN68SFAvH4BeCyI9P5q5H/WGK8uBZ85LSxCkoc+2k1tqB/vARU6ElgxMRqvHKSV0t0KJ4FzqUXlICOvS0iPXt23OrA5wBKnkRTcYN/Ypa43vDi11h8qkmtw2u7TuxIzxNtfznD8pwTx3T4Qkh7OujAGqmiO8JFIcO/J6dfDF1Ftgpk9jlhE22m6S4eG+1HAsBtNj4GpgYj/NATkYVEEARLZRb30CRPC2ykn+ErcFAd1ueSUTzrhOMgIAY4SuAAfbbLzYhePBE3DQFdhEDhvfLZK/wMQHMyh+8H5QPOhQSXhZt1LtbwhKUnJjbwpJxSo7OnWa0ar4xmsl3wRKuQYNBNZg+sMWHHxhwcBrsPEdNlVbPnRkLgXi1AwASfIWNQODNYQhhsgPcBgD5FAK3goSdiDV8h8gFMTrePKLIruOvHBWZvH7EQtfP6uyVuyHLkQOVP6YjH+qMVh38BQLceyWQD8Z12Zgk6SLstMpY6f0Rgr+SNyVF9dI7rzNzBKh3OetyIh1DslUFERO2q+brulGBieID6IgLJV0b7txKg/mGV85VQ5OjmW7IGKrHJA/S6wOxtiYvnjMzKJFs3BuVgNxzH4QIj1OLqu7C5qFYCJ7+0MAlr1Es3aBrevVQHsw1u+QoctK2j1bF947FnvBvX75jJyKrHhF3LLebMYi/aN+geKlRHqR21Gx3UG8/riwqje4Qr+Iz8PN/g+4s2Ychnb1wtAm+Rrqvr1YpOEaRigOAPZCNYgQ/m3yajp+sehdMH5Rortf</div></div>



*In this example I used address from my running program, yours will be different*

The `ptr` variable (at the address `0x003ef81c`) contains a **value** of `0x003ef810` 
which **points to** the `number` variable at that address. To access the value `42` you 
simply write `*ptr`.

**Note**: *it is rather silly to have a pointer to the local variable! In that case, just 
use the variable. I do that here so it's easier to understand. Next we look at situations
where you *need* to have a pointer*.

#### Dynamically allocating memory

Sometimes you need to get some memory dynamically:
``` cpp Dynamically allocating memory
    // dynamically allocating memory
	double *ptr_d = new double;

	*ptr_d = 142;
	cout << *ptr_d << endl;

	delete ptr_d;
```

You do that by asking for memory using a `new` keyword. Notice how mentioning 
the type (`double` in this example) is needed so the compiler know how many
bytes to allocate? 

Also notice that although we declare the `int *ptr` and `double *ptr_d`, 
they both are just **pointer variables**. The type is actually 
used to detect the size of the **pointed to** memory!

And lastly, one needs to release the allocated memory. You do that using the
`delete` keyword (you're not actually deleting anything, just notifying 
the OS that you don't want it any more). 

**Note** 
You don't actually *have to* release it because the OS will detect that your 
program is not using that memory any more and will reclaim it on it's own.
And that's OK with small testing programs that don't run for long, but if you
are writing programs that run for long times and never exit (i.e. some
server programs) than it would be good to release the memory that you actually
don't need.

### References

A reference is just **an *additional* name for already existing variable**. 
The main point is that the variable you reference must already exist. 

``` cpp References
	// references
	int &ref = number;

	cout << ref << ' ' << number << endl;
```

That will print `42 42` because the variable `number` contains a value of `42` 
and the variable `ref` just references it.

Again, the picture is the best:
<div class="mxgraph" style="position:relative;overflow:hidden;width:152px;height:65px;display:inline-block;_display:inline;"><div style="width:1px;height:1px;overflow:hidden;">rZRBb4MgFIB/jcc2CGrrta7dLjt1yc62opIhGMRN++uH5VmlrsmWzIOB7+Hj8T2iR5Kqe1ZpXb7KjHIPo6zzyJOH8RYh8x5AfwcKxTKLfAAty2jjIC0l16x24VkKQc/aYbnkbrI6LegCHM8pX9J3lukSisPRxF8oK8pxGz+KbaTR/Zgjo3nacr26ImzDHbKxAJb34zwcEwungIuUlQMUbdjFLTJnUAWYO0mVUeUgzsTH3BLZeyRRUmo7qrqE8qEto3L72eFB9CZHUaF/8wEc/jPlLZQe4IWuXAqdSC5t5QShKCLEI7uBH+2ZcQCJqNK0e1jMdERz66isqFb94N5GQ7RG8wcSwP3bgLGvqet+CKycdTwAloLW4rbP5MEMQMXPWshCi2irk2kdTq6dzheOzKnN/rumTs9MFG+yNngVgiRHHkKHgyvP3/6/PNddsHHNRsHSZRCv4/mzNOvfrYjJn02b6XS5r7HZz4fsvwE=</div></div>

So, what's the difference between the pointer and the reference? Well, the pointer can
point to **nothing** and the reference must have a valid variable to point to. Wait, what, 
point to *nothing*? Yes, the pointers can take on a *special value* of **null**. 
That's written as plain integer zero (`0`) or a [macro](http://en.wikipedia.org/wiki/C_preprocessor#Macro_definition_and_expansion) `NULL`. 

New C++ 0x11 defines a new keyword `nullptr` which serves the same purpose and
should be used (writing zero complicates things in some circumstances: 
[some details here](http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/nullptr)).
``` c++
	// pointer to nothing
	string *ptr_s = nullptr;
```
It's main usage is when you need to tell that you don't know the value of someting.

### Functions
Very simplified, the function is a block of code with a name. The usual declaration
in C++ is:
``` c++
    return_type function_name(parameter_list);
```
This way you name a function as `function_name`, say that it will return some
value of type `return type` and that it accepts some parameters named in
`parameter_list`.

The `return type` can be any of regular C++ types. It can additionally be a `void`
which means that function won't return a value.

The `function_name` must conform to usual naming rules (letters, numbers and underscore, 
first must not be a number, can not be a keyword). More details 
[here](http://msdn.microsoft.com/en-us/library/565w213d.aspx).

The `parameter_list` is a list of declarations of variables. It can be
empty or declared `void` both of which mean *no parameters*. If parameters
are given, then their types and order are significant. We declare a function
and give her a **body**:

``` c++ Definition of a function
    int sum(int x, int y) {
    	int result = x + y;
    	return result;
    }

```

This function accepts two parameters, both of which are integers, and returns an
integer. It's name is `sum`. We can **call** it like this:

``` c++
	// calling a function
	int r = sum(16, 42);
	cout << "Sum of 16 and 42 is " << r << endl;
```

That, obviously, outputs the string `Sum of 16 and 42 is 58`. 

The body of the function (the block of code delimited with braces `{` and `}`) 
*calculates* the sum, remembers it in a variable `result` and finally 
*returns* the calculated value to the caller.

#### Sending values to functions
C++ has three mechanisms for calling a function:

1. pass by value
2. pass by reference
3. pass by pointer

##### Pass by value
When you pass some variable by value, that means it's **copy** is passed to
the function. The function can do anything to that copy and that would not
be reflected on original variable.

##### Pass by reference
When you pass some variable by reference, that means it's **name** is passed to
the function. Whatever the function does to that variable is reflected on the 
original variable.

##### Pass by pointer
When you pass some variable by pointer, that means it's **address** is passed to
the function. Whatever the function does to that variable is reflected on the 
original variable.

### Coding challenge
Write a function using all three mechanism named `void my_swap(??, ??);` that when 
passed two values it replaces them so the next code produces correct output:

``` c++
	int x = 16;
	int y = 42;

	// outputs: 16 42
	cout << x << " " << y << endl;

	// call function here

	// outputs: 42 16
	cout << x << " " << y << endl;
```

Second call to output **must** produce `42 16`. The only thing you can do in
this block of code is call the function. 

**Note**: spend enough time on this so you become familiar with it and it 
doesn't feel weird. It's **very** important you understand this.


### Files

Files are a cornerstone of computers and data: everything you want to somehow 
store and preserve you write to a file. There are many, many ways to go 
about creating and reading files, so we'll cover just the essentials here.

#### Reading from files
When working with files is C++ you must `#ınclude <fstream>`. You access a file
in the file system by creating a variable of type `ifstream` for reading files
and of type `ofstream` for writing to file.

``` c++ Opening a file
	// reading files
	ifstream dat_in("filename.txt");

	if (!dat_in) {
		cerr << "Error opening 'filename.txt'" << endl;
		return 1;
	}

	// read from file
```

We first create a variable named `dat_in` which we then use to **test** if 
the binding to actual file succedded with `if (!dat_in)`. If the file
is not succesfully opened, we can't continue (we have no file to read from).
In that case we inform the caller by writng an error message to the error 
stream (that stream is usually connected to the console). Read more about cerr 
[here](http://www.cplusplus.com/reference/iostream/cerr/). We also return some
other value that is not zero (zero usually means *all OK*).

If, on the other hand, the file stream is opened, we can continue to use it.ž
Let's assume that file `filename.txt` contains some integer numbers. Then we 
can read those numbers in a loop with an extraction operator `>>`.

``` c++ Reading integers from a file
	while (!dat_in.eof()) {
		int value;
		dat_in >> value;

		cout << value << ' ';
	}
```

The test in the `while` checks if the file is at the and. If it's **not** then the
body of the *while* is executed. It declares a variable (a piece of memory) in
which to store the number which it reads in the next line with the operator `>>`.

Just for show, we output what we got from file (plus a space). 

The fact of reading from a file moves the *file pointer* a few bytes forward. With 
that happening in a loop, eventually we'll read whole of the file and reach it's end.
When that happens `dat_in.eof()` will return `true` and the loop will finish.

### Coding challenge
Suppose you have a file of **real** numbers (create one if you don't). Write a 
function  that accepts a filename as a parameter and reads its's contents outputting 
every value in it's own row. 

Watch out for differences in representing real numbers as strings: 
some have a dot `.`, and some have a comma `,` separating the decimals. C++ will 
accept only dots.


#### Writing to files

Writing to a file is similar to reading from it, it's just accepting new values
instead of giving out values.

``` c++ Write to a file
	ofstream dat_out("fileout.txt");

	if (!dat_out) {
		cerr << "Error creating 'fileout.txt'" << endl;
		return 2;
	}

	int num;
	do {
		cout << "Enter an integer: ";
		cin >> num;

		if (num != 0) {
			dat_out << num << ' ';
		}
	} while (num != 0);
```

We go through the same ritual as we did when opening a file: create a variable,
bind it to a file and check if that succedded.

After that, we prepare a variable to read from console, notify the user of 
what we want him to do (enter an integer, please), and write it to file using
operator `<< `. We do that in a loop, waiting for user to enter a zero.

#### Binary files

And the last thing to learn today is to look at binary files. Up to now we only
worked with text files: each byte in a file represents a character according
to an [ASCII table](http://www.asciitable.com/) (files can have other encodings,
such as [utf-8](http://www.utf-8.com/), but we'll keep it simple and explain 
just for ASCII files). So, when you want to store a number, say `42` in a text file
it will consume `2 bytes`: one for `4` and one for `2`. 

When you want to store that same number in a binary file, you store all of the bytes
for a given type. And if we use and `int` to store the `42`, then we use `4` bytes 
(on most platforms an `int` is `4` bytes). 

``` c++ Writing numbers from 16 to 42 in a binary file
	ofstream dat_out_bin("numbers.dat", ios_base::binary);

	if (!dat_out_bin) {
		cerr << "Error creating file 'numbers.dat'" << endl;
		return 3;
	}

	// write some numbers
	for (int i = 16; i <= 42; ++i) {
		const char *from_addr = reinterpret_cast<const char *>(&i);
		dat_out_bin.write(from_addr, sizeof(int));
	}
```

Again the usual opening and checking. After that we loop for numbers from 16 to 42
and write their binary representation to the file. 

C++ has rather limiting support for writing bytes to a stream: 
it *always* wants a pointer to constant character and a number of bytes. 
We get number of bytes with operator `sizeof`, and we can always force the C++ 
compiler to **reinterpret** some memory for us. That's what the line 10 does:
it reinterprets the address of an integer variable `&i` as an address of an 
`const char*` variable.

Rather good and detailed article is [here](http://www.cplusplus.com/articles/DzywvCM9/).

We read that same file ### Files

Files are a cornerstone of computers and data: everything you want to somehow 
store and preserve you write to a file. There are many, many ways to go 
about creating and reading files, so we'll cover just the essentials here.

#### Reading from files
When working with files is C++ you must `#ınclude <fstream>`. You access a file
in the filesystem by creating a variable of type `ifstream` for reading files
and of type `ofstream` for writing to file.

``` c++ Opening a file
	// reading files
	ifstream dat_in("filename.txt");

	if (!dat_in) {
		cerr << "Error opening 'filename.txt'" << endl;
		return 1;
	}

	// read from file
```

We first create a variable named `dat_in` which we then use to **test** if 
the binding to actual file succedded with `if (!dat_in)`. If the file
is not succesfully opened, we can't continue (we have no file to read from).
In that case we inform the caller by writng an error message to the error 
stream (that stream is usually connected to the console). Read more about cerr 
[here](http://www.cplusplus.com/reference/iostream/cerr/). We also return some
other value that is not zero (zero usually means *all OK*).

If, on the other hand, the file stream is opened, we can continue to use it.ž
Let's assume that file `filename.txt` contains some integer numbers. Then we 
can read those numbers in a loop with an extraction operator `>>`.

``` c++ Reading integers from a file
	while (!dat_in.eof()) {
		int value;
		dat_in >> value;

		cout << value << ' ';
	}
```

The test in the `while` checks if the file is at the and. If it's **not** then the
body of the *while* is executed. It declares a variable (a piece of memory) in
which to store the number which it reads in the next line with the operator `>>`.

Just for show, we output what we got from file (plus a space). 

The fact of reading from a file moves the *file pointer* a few bytes forward. With 
that happening in a loop, eventually we'll read whole of the file and reach it's end.
When that happens `dat_in.eof()` will return `true` and the loop will finish.

### Coding challenge
Suppose you have a file of **real** numbers (create one if you don't). Write a 
function  that accepts a filename as a parameter and reads its's contents outputing 
every value in it's own row. 

Watch out for differences in representing real numbers as strings: 
some have a dot `.`, and some have a comma `,` separating the decimals. C++ will 
accept only dots.


#### Writing to files

Writing to a file is similar to reading from it, it's just accepting new values
instead of giving out values.

``` c++ Write to a file
	ofstream dat_out("fileout.txt");

	if (!dat_out) {
		cerr << "Error creating 'fileout.txt'" << endl;
		return 2;
	}

	int num;
	do {
		cout << "Enter an integer: ";
		cin >> num;

		if (num != 0) {
			dat_out << num << ' ';
		}
	} while (num != 0);
```

We go through the same ritual as we did when opening a file: create a variable,
bind it to a file and check if that succedded.

After that, we prepare a variable to read from console, notify the user of 
what we want him to do (enter an integer, please), and write it to file using
operator `<< `. We do that in a loop, waiting for user to enter a zero.

#### Binary files

And the last thing to learn today is to look at binary files. Up to now we only
worked with text files: each byte in a file represents a character according
to an [ASCII table](http://www.asciitable.com/) (files can have other encodings,
such as [utf-8](http://www.utf-8.com/), but we'll keep it simple and explain 
just for ASCII files). So, when you want to store a number, say `42` in a text file
it will consume `2 bytes`: one for `4` and one for `2`. 

When you want to store that same number in a binary file, you store all of the bytes
for a given type. And if we use and `int` to store the `42`, then we use `4` bytes 
(on most platforms an `int` is `4` bytes). 

``` c++ Writing numbers from 16 to 42 in a binary file
	ofstream dat_out_bin("numbers.dat", ios_base::binary);

	if (!dat_out_bin) {
		cerr << "Error creating file 'numbers.dat'" << endl;
		return 3;
	}

	// write some numbers
	for (int i = 16; i <= 42; ++i) {
		const char *from_addr = reinterpret_cast<const char *>(&i);
		dat_out_bin.write(from_addr, sizeof(int));
	}
```

Again the usual opening and checking. After that we loop for numbers from 16 to 42
and write their binary representation to the file. The file *looks* like this:

{% img center /images/02_binary_file.png 'Binary file' 'Output from running the example' %}

The left part contains bytes (represented as hexadecimal values) in little-endianess ordering
(read about endianness [here](http://en.wikipedia.org/wiki/Endianness)). That means that
the first four bytes `10 00 00 00` represent `16`.

C++ has rather limiting support for writing bytes to a stream: 
it *always* wants a pointer to constant character and a number of bytes. 
We get number of bytes with operator `sizeof`, and we can always force the C++ 
compiler to **reinterpret** some memory for us. That's what the line 10 does:
it reinterprets the address of an integer variable `&i` as an address of an 
`const char*` variable.

Rather good and detailed article is [here](http://www.cplusplus.com/articles/DzywvCM9/).

##### Reading


We read that same file similarly as before, we just need to force the memory to which we
write to be of `char *` type (now of course, without the constant).

``` c++ Reading from binary file
    dat_out_bin.close();

	ifstream dat_in_bin("numbers.bin", ios_base::binary);
	if (!dat_in_bin) {
		cerr << "Error opening file 'numbers.bin'" << endl;
		return 4;
	}

	cout << endl;
	// read some numbers
	while (!dat_in_bin.eof()) {
		int value;
		char *to_addr = reinterpret_cast<char *>(&value);
		dat_in_bin.read(to_addr, sizeof(int));

		cout << value << " ";
	}
```

We have to `close() ` the output file so we can open it again in the read mode. Try to
read from file when you remove the first line and you'll get *garbage-out*&copy;.

We read from the file using the `read()` function which as a first parameter wants a
`char *` to a memory and a number of bytes to read.


The whole example file can be downloaded 
from <a href='/downloads/code/part2.zip'>here</a>.


<script type="text/javascript" src="//drawdotio.appspot.com/embed.js"></script>
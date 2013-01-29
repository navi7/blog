---
layout: post
title: "basics of c++ and visual studio - part1"
date: 2013-01-22 12:53
comments: true
categories: programming
---

This will be a series of post on how to start programming with C++ and a
Visual Studio IDE. We'll use Visual Studio 2010.


Basic Stucture
---------------

Visual Studio 2010 organizes source files into hierarchies called **Projects**,
and then organizes **Projects** into **Solutions**.

{% pullquote %}
You don't create the *Solution* directly, rather you create "New Project", select the type of the project from templates (they are organized differently depending on the installation) and VS creates both.

*Note:* {" one solution is one directory "}. The project in the solution can be in a subdirectory (preferred if you want multiple projects in a solution) or in the same directory.
{% endpullquote %}

Next, in the templates, select the **Win32 Console Application**. Name the project, select location for files and directories and name the solution. They can both be the same. If you'll make just one project, it's ok to disable the *"Create directory for solution"* option. I'll leave it on so I can add more projects later.

That runs a wizard (really an unnecessary complication, but that's the way it is), press *Next* once to go to the second page. There check the **Empty project** option under *Additional options* and press *Finish*. That creates an *empty* C++ project.

Adding source files
--------------------

Next, add a source file to the project. You can do that in many ways, for example *right click* on project name in *Solution explorer* and select *New item...*.

{% pullquote %}
That presents another wizard. This time select **C++ file** from the list and *enter a name*. {" For many projects I usually create file named "program.cpp" "}. That file always contains my main() function.
{% endpullquote %}

Finally, add some code to the **program.cpp** file:

{% include_code program.cpp %}

Then **compile and run** the program. Look for a menu options **Build -> Build Solution** and **Debug -> Start Without Debugging**.

That should output the text sent to the console:
{% img right /images/hello-world-output.png 'Output' 'Output from runnung the example' %}


### Important

{% blockquote %}
You should always first compile programs and then run them using "Start Without Debugging" option. "Debug" option is used when you actually want to "debug".
{% endblockquote %}

# Rave's Default C++-23 Project

This is a simple, dirty, default C++23 project.

C++ source files are .cpp, C++ module interfaces are .cppm.

Yes, this uses globbing, but there are enterprise projects that use this workflow where they just do touch to trigger a CMakeLists.

If you are a beginning, the is more than enough to get stuff working. For multiple build types, pelase refer to the wordlr project.
I can assure you, if you are doing any copying and pasting as part of your build process or doing some weird softlinks or hardlinks or shortcuts
with the sources, you really should focus on learning C++, learning a normal build system, on a somewhat normal os, before messing with that stuff.

Reach out to fellow devs, too. AI technical websites have been popping up and have been giving iffy advice. Might be 90% - 0% accurate, but code
must be 100% accurate. Code is a highly literal art. If you mess up even a line, it will either not compile, or do something wrong which could cause damage.

"off by one" errors are so common that they are a technical term.
# Installing git
Just look it up on duckduckgo. Do the official git webssite, not the Ai overview or the ai generated blogs (you can tell because the article names
look like search terms/the "bloggers" don't exit or its really just a massive article repo with just weirdness).

Again: AI does hallucinate, and by asking fellow devs or going to the official site or reading the README (which is titled "read me" in ALL CAPS for a reason)
somewhat thoroughly, you'll get good results.

By talking to fellow devs, you'll make good friends. Have a mustard seed of faith in humanity.

# Installing a compiler
Look up C++ compiler for your platform. Liux is the easiest. Windows is the 10th circle of damnation.

# Installing Ninja
https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages

To be frank, if you are not using one of the numerous OS's on the Ninja site, you're either really advanced to
where you can figure out how to install ninja on your own, getting into that world, or should rethink your decision,
or find a friend to guide you, or embrace masochism in this technical exercise. (And there
is direct support in archlinux, too! Archlinux! - A masochistic distro.)

# Building
Do the below in order
Downloading
```
https://github.com/RavenRandomz/ravens-default-cpp23-project.git
```
Generating
```
cd ravens-default-cpp-project # if you are already in this dir, do not run this line
mkdir build
cd build
cmake .. -G Ninja #Ninja is cross platform and is one of the few project types that supports modules at the moment with CMakef
```

Subsequent builds
```
cd build
ninja
# or to utilize parallel processing for that 1337sp33d
ninja -j 0 

```

When you add a file (assuming you are in build dir and already generated the ninja project
```
touch ../CMakeLists.txt # Cmake must believe that the file has "changed" so it can check for stuff
ninja # Will automatically run cmake
```

Alternatively when you add a file - imo, just install coreutils, idk why windows hasn't shipped with them: https://gnuwin32.sourceforge.net/packages/coreutils.htm
```
vim ../CMakeLists.txt # (or whever you use)
# Edit the file in some manner, add a
```

When you are getting into gdb

Mote that as long as the project type is a ninja one
within the build dir, cmake will just update it to use debug
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug #Ninja is cross platform and is one of the few project types that supports modules at the moment with CMakef
```

When you want a build without debug symbols/assertions https://gnuwin32.sourceforge.net/packages/coreutils.htm
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release #Ninja is cross platform and is one of the few project types that supports modules at the moment with CMakef
```

# Recommended ide
Use nvim with coc-clangd for completion (this generates a compile-commads.json). It works out of the box ^_^

Also, if you want to become better, code without lsp but with auto-indent. Read here: [https://news.ycombinator.com/item?id=42492508]

It forces you to reckon with poorly structured project design and improves memory. Slightly slower, but forces your to make
your code architecture efficient and friendly.

yes, code completion is a tool, and AI might be a tool, but consider the MERIT of what you are doing. If you are just doing what a manager
who cannot code is doing, then you are no longer a coder. If you cannot write syntax but just trust/hope the coder is correct, then you are not a coder.
If you cannot debug, if you are just saying "please fix" etc.

Likewise, code completion can lead someone to forget or atrophy in codebase knowledge. Muscle memory is very powerful. Try an experiment: try to code
without code completion and see how well you can do so. If it didn't atrophy you ability, you should be able to code without stuttering.

If I am running in a race and I use a car, yes, it is a tool, but I do not have the merit of a runner.

I will say however, that I find the goto feature (part of clangd and general lsp) really useful for unfamiliar codebases/exploring them.

Vscode is heavily bulky and it gets weird to the point where you are told to just use cmake for having a project with multiple files.
It has some strenths, but otherwise is the 11th circle of 2nd hell. I have talked with more advanced programmers and they have told me that
I'm not just a command-line addict. In some environments, you won't be allowed to install all of the bulky vscode tools. Understanding how to
work without a desktop gui is priceless. It also gives you insight into how things are compiled etc.


[https://neovim.io/]

[https://github.com/junegunn/vim-plug]

[https://github.com/neoclide/coc.nvim]

[github.com/clangd/coc-clangd]


# Architecture notes
This allows you to utilize modules. Note that whenever you add a file, you must use touch on the CMakeLists.txt to change its modified time so that cmake can be triggered
to search for new files during the build

If you want to manually list sources, it's pretty obvious on how to adapt it, CMake documentation has plenty of examples. I just don't get the redundancy.

# License
This is dual licensed under UNLICENSE and GPLv3. GPLv3 is to prevent patent and DRM aggression. Theoretically, someone could use this as part of a patent
or DRM or trade secret, so GPLv3 licensing prevents them from being able to sue eveyrone use for using this code. It's stupid, but ay, it's the law and lawyers :P

I don't know how the dual license helps protect it if it's already under Unlicense, but the Rust Project licenses Rust under Apache to protect against aggression
and MIT in order to be compatible with gpl code. Go figure ^_^

# Adding more advanced features + project reference
Check out the CMakelists.txt here - it adds gtest, boost (examples of dependencies), traditional include and cpp files, and multiple builds:
[https://github.com/RavenRandomz/wordlr]

Shameless self-advert, but this project was adapted from this.
# Wordlr module architeture notes
The rationale with the use of modules was to leverage their ability to not split a class definition and its mmber function definitions so that everything is in one file.
So I did just that. With the convention of doing library_name/catagory/subcatgory/etc/header, without expecting for doing #include libraryname/catagory for adding everyhing,
(which you can define a catagory.hpp), then library.catagory.module, is my conventoin.

Yes, as a C++ worshipper of Keith the Obese Rat, some argue that it may be more conducive for C++, but DRY, and the fact that many other major coding languages, successful ones
are able to do this with clear documentation, and just use a tool like doxygen to show the interface with documentation text, and that this use of headers originated as a hack to
modularize code via copying a pasting the entire fire and whatever fires in copies and pastes before compilation began, then allowing partial declarations so the compiler wouldn't complain.

Other issues: Leaking preprocessor macros to the point where the solution is reordering the inclusion, cumbersome duplicative boilerplate for formal header guards (don't worry, I understand
they support really weird build systems, but since we have moules we can do cleaner things, and let the weird ones do their thing, or add weird things in isolation.

In my, potentially controversial, 1337sp34k-loving, gnu-maillist-loving, irc-loving, discord-hating, f1r3f0x-qu35710n1n6 s31f'5, opinion, is just something we need to move on. Yes, there are
edge cases, even in wordlr, where I have to use the occassional headder/cpp pair, but that is the exception, not the rule. I am not advocating for the erradication of header support since backwards
compatibility is important. Forwards compatibility doesn't invalidate that.

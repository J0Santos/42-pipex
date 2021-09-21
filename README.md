# Pipex :postbox:

## Grade 🧑‍🎓

![Grade](https://github.com/J0Santos/42-pipex/blob/c00f67eecb54837db3b8c78196eef72b6a13e964/Readme_utils/Grade.png)

## Introduction

#### -----> [PDF]()

The project was made to recreate what a pipe does.

It should work by using the following command line:
'./pipex infile "cmd 1" "cmd 2" outfile'

  - 'infile' being the file that contains the information you want treated;
  - 'cmd 1' is the first command you want to be executed on the 'infile';
  - 'cmd 2' is the second command that will be executed on the output of 'cmd 1';
  - 'outfile' is the file where the result of 'cmd 2' will be stored;

An example of this could be: './pipex chicken_recipe.txt "cat -e" "wc -l" recipe_length.txt' which would gives me the number of lines the infile has.

## Method 🧪

This project is quite straight forward. There are a few ways to do it, but they all revolve around the same idea.

There are a few videos from ![CodeVault](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY) on youtube that explain in a lot of detail how to get this done.

I also used these guides to help me with some questions I had during the project:

- https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
- https://bigpel66.oopy.io/library/42/inner-circle/8 (If you dont know Korean, use a translator. If you do know, lucky you)

## Observations

The 'execve()' function works in the following way:

```C
int execve(const char *pathname, char *const argv[], char *const envp[])
```




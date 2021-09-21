# Pipex :postbox:

## Grade 🧑‍🎓

![Grade](https://github.com/J0Santos/42-pipex/blob/c00f67eecb54837db3b8c78196eef72b6a13e964/Readme_utils/Grade.png)

## Introduction

This project is the discovery in detail and by programming of a UNIX mechanism that you already know.

#### -----> [PDF]()

The project requires you to recreate what a pipe does.

It should work by using the following comamnd line:
'./pipex infile "cmd 1" "cmd 2" outfile'

  - 'infile' being the file that contains the information you want treated;
  - 'cmd 1' is the first command you want to be executed on the 'infile';
  - 'cmd 2' is the second command that will be executed on the output of 'cmd 1';
  - 'outfile' is the file where the result of 'cmd 2' will be stored;

An example of this could be: './pipex chicken_recipe.txt "cat -e" "wc -l"

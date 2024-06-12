#!/bin/bash
# Chapter 1: Basics 

# A shell script is a file that contains one or more commands

# First program 
echo "Hello, World!"

# This is a single line comment " : '' "
: '
This
is
an
multiline
comment
'

<<<This is also multiline comment
It spans multiple lines.

# To print the PATH environment variable
echo $PATH

# To check file permissions
ls -ltr


##  Commands

# 1. pwd: Prints the name of the current working directory
pwd

# 2. cd: Changes the shell’s working directory
cd /tmp
pwd

# 3. echo: Prints its arguments separated by a space and terminated by a newline
echo "Hello, World!"
echo "Hello" "World" "from" "Bash"

# 4. type: Displays information about a command
type echo
type cd

# 5. mkdir: Creates a new directory
mkdir newdir

# Verify that the directory was created
ls -l

# 6. chmod: Modifies the permissions of a file
touch file.txt
chmod 744 file.txt

# Verify the file's permissions
ls -l file.txt

# 7. source: Executes a script in the current shell environment
echo "Creating example.sh script"
echo -e '#!/bin/bash\n\n# Print a message\necho "Script executed"' > example.sh
chmod +x example.sh
source example.sh
. example.sh

# 8. printf: Prints the arguments as specified by a format string
printf "Hello, %s!\n" "World"
printf "%-10s %-8s %-4s\n" Name Gender Age
printf "%-10s %-8s %-4s\n" Alice Female 30
printf "%-10s %-8s %-4s\n" Bob Male 25



# Ch1 : Exercises

: '1.Write a script that creates a directory called bpl inside 
$HOME. Populate this directory with two subdirectories: bin and 
scripts.'

#!/bin/bash
cd $HOME
mkdir bpl
mkdir bpl && mkdir bpl/script


: '2. Write a script to create the “Hello, World!” script, hw, in $HOME/
bpl/bin/; make it executable; and then execute it.'
#!/bin/bash
cd $HOME/bpl/bin
echo echo Hello , World! > hw
chmod +x hw
hw


: ' 3. Make the modifications to now enable running the script using 
the command hw instead of /bpl/bin/hw from the user home 
directory.'
#!/bin/bash
PATH = $PATH :$HOME/bpl/bin
echo Sucess
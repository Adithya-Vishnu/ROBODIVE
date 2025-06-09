## 

## PART-1

In part-1 we use the mkdir function to create a parent directory “LinuxLearning” and after using cd to change the directories to ‘LinuxLearning’ we use mkdir again to create three new sub directories.

next we use the command of the format echo “text to be entered” > filename. to create three new files. and similarly after using the first line to create the files we use the following variation to append two more lines to each file. echo “text to be entered” >> filename

and since in the question its specified that these files should be inside the respective sub directories we use the mv function to do this . 

## PART-2

For this we use the command cp in the format

 cp [filename] [directory location] 

mv is also used to move the file. and an important thing to keep in mind is that ’.’ can be used to specify the current directory which is open.

The rm command is used to remove any file required and rmdir is used to delete ‘empty’ directories and rm -r is a powerful tool used to delete any file or directory irrespective of whether it is empty or not.

And pwd is used to find the location of the currently open directory or location 

## PART-3

The cat command which stands for concatenate is used here, which displays the contents of the files. The cat command is used in the format cat [filename/location]. This is done for the three files.f the file size is too large we can also use the less pager option to view it page by page.

The wc command is used to output the word or line count of a file. the wc -l can be used to give the number of lines in the file. This is done for the three files.

grep command is used to find a specific word or character in the file. format is grep [object to be found][filename] and the lines with the word are returned with highlighted word.

sort command is used to sort the text file. The sorting can also be done in reverse using the sort -r command. Sorting is mainly used in placed where the uniq function is to be used where it is required that the repeated lines be adjacent to each other so this can be used there too.

## PART-4

The ls -l can be used in a directory to give the file permissions of each content in the directory or we could use it as ls -l [filename] which would give the permissions of the specified file name only. in the out put if it begins with ‘-’ it means it is just a normal file, -rw means read and write allowed, user-owner, group-whatever the group is.

chmod function is used to change the rights of the file. this can be done in two methods using 

chmod 400 [filename]

or

chmod u=r [filename]

chmod go-rwx [filename]

chown: command is used to change the ownership of the file or directory

format: chown [new owner] [filename]

## PART-5

whoami - outputs the current users name

uname - outputs the unix system’s name here LINUX

df - prints the approximate disk space

ps - lists the current running processes.

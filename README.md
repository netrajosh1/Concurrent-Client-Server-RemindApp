# Concurrent Client-Server Reminder Application

This project implements a reminder application that can handle multiple reminders concurrently. Users can set reminders through command line arguments or by providing input during runtime.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Code Structure](#code-structure)
- [Functions](#functions)
- [Makefile](#makefile)

## Overview

The Concurrent Client-Server Reminder Application allows users to set reminders with specified sleep intervals. The application is designed to handle both command-line input and user prompts during execution. Each reminder is managed in a separate process, enabling concurrent execution.

## Features

- Set reminders using command-line arguments.
- Specify sleep intervals before displaying the reminder message.
- Concurrent handling of multiple reminders through process forking.
- Input validation to ensure correct format for intervals.

## Code Structure
Code Structure
The application consists of multiple source files, each handling specific functionalities:

main.c: Main program that orchestrates reminder setting and process management.
numchecker.c: Validates if the input strings are numbers.
printreminder.c: Prints the reminder message.
setsleepinterval.c: Parses the input to set sleep intervals.

## Functions
This section outlines the key functions implemented in the Concurrent Client-Server Reminder Application, along with their descriptions and parameters.

### numchecker

```c
bool numchecker(char *numstr);
```

Description
Validates if the input string consists only of digits. It checks for negative numbers and returns false if any character is not a digit.

Parameters
- numstr: A pointer to a character string representing the number to be validated.
Returns
- true if the input string is a valid non-negative number.
- false if the input string contains non-digit characters or is a negative number.

### printreminder

```c
void printreminder(char *toprint);
```

Description
Prints the reminder message provided to the user. It also re-prompts the user for further input.

Parameters
- toprint: A pointer to a character string containing the reminder message to be printed.

### setsleepinterval

```c
int setsleepinterval(char *remindrequest, int **interval);
```
Description
Parses the reminder request input to extract sleep intervals. Allocates memory for the intervals and populates it based on the parsed input.


Parameters
- remindrequest: A pointer to a character string containing the entire reminder request input.
- interval: A pointer to a pointer of integers, where the extracted sleep intervals will be stored.

Returns
- The number of sleep intervals extracted from the input.



### Command-Line Arguments

You can run the application with command-line arguments to set reminders directly. The first argument should be one or more sleep intervals followed by the reminder message. 

**Example:**

```bash
./remindapp 5 10 "Take a break"

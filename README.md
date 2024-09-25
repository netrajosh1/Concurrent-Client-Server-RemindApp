# Concurrent Client-Server Reminder Application

This project implements a reminder application that can handle multiple reminders concurrently. Users can set reminders through command line arguments or by providing input during runtime.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Functions](#functions)
- [Makefile](#makefile)
- [Contributing](#contributing)
- [License](#license)

## Overview

The Concurrent Client-Server Reminder Application allows users to set reminders with specified sleep intervals. The application is designed to handle both command-line input and user prompts during execution. Each reminder is managed in a separate process, enabling concurrent execution.

## Features

- Set reminders using command-line arguments.
- Specify sleep intervals before displaying the reminder message.
- Concurrent handling of multiple reminders through process forking.
- Input validation to ensure correct format for intervals.

## Usage

### Command-Line Arguments

You can run the application with command-line arguments to set reminders directly. The first argument should be one or more sleep intervals followed by the reminder message. 

**Example:**

```bash
./remindapp 5 10 "Take a break"

#pragma once

#include <iostream>
#include <signal.h>
#include <cstring>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <string>
#include <time.h>

#define MAXBUFF 1024

using namespace std;

void Write2File(char *);
void ReadFromFile(char *);



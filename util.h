#pragma once
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "log.h"
#include <string.h>
int hardLinkReplace(char *existinfFile, char *newLink);
int DeleteFile(char *path);
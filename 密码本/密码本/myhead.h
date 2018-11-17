#pragma once
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "math.h"

typedef struct PASSWORD
{
	char website[WEBSEIT_SIZE];
	char account[ACCOUNT_SIZE];
	char password[PASSWORD_SIZE];
	char mark[MARK_SIZE];
}PASSWORD;

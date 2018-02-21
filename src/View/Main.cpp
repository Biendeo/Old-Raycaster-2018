#include <iostream>

#include "View.h"

int main(int argc, char* argv[]) {
	View view(new Engine());

	view.InitialiseSDL();

	view.Loop();

	view.DisposeSDL();

	return 0;
}
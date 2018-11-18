First, you must put a Pokémon Mystery Dungeon Red Rescue Team 1.0 (US) ROM in the root directory of the repository and name it `baserom.gba`. It should have a SHA1 checksum of `9f4cfc5b5f4859d17169a485462e977c7aac2b89`. Then, follow the OS-specific instructions below.

# Linux

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Make sure that there is an environment variable called DEVKITARM with the path of the directory before the "bin" directory containing "arm-none-eabi-as", "arm-none-eabi-cpp", "arm-none-eabi-ld" and "arm-none-eabi-objcopy".

Then get the compiler from https://github.com/pret/agbcc and run the following commands.

	build.sh
	install.sh PATH_OF_PMD-RED_DIRECTORY
	${DEVKITARM}/bin/arm-none-eabi/ranlib PATH_OF_PMD-RED_DIRECTORY/tools/agbcc/lib/libgcc.a lib/libc.a

Then in the pmd-red directory, build the tools.

	build_tools.sh

Finally, build the rom.

	make

# Windows

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Then get the compiled tools from https://github.com/pret/pokeruby-tools. Copy the `tools/` folder over the `tools/` folder in your pmd-red directory.

You can then build pmd-red using `make` in the MSYS environment provided with devkitARM.

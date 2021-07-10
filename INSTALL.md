<<<<<<< HEAD
First, you must put a Pokémon Mystery Dungeon Red Rescue Team 1.0 (US) ROM in the root directory of the repository and name it `baserom.gba`. It should have a SHA1 checksum of `9f4cfc5b5f4859d17169a485462e977c7aac2b89`. Then, follow the OS-specific instructions below.

# Linux

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Make sure that there is an environment variable called DEVKITARM with the path of the directory before the "bin" directory containing "arm-none-eabi-as", "arm-none-eabi-cpp", "arm-none-eabi-ld" and "arm-none-eabi-objcopy".

Then get the compiler from https://github.com/pret/agbcc and run the following commands.

	build.sh
	install.sh PATH_OF_PMD-RED_DIRECTORY
	${DEVKITARM}/bin/arm-none-eabi/ranlib PATH_OF_PMD-RED_DIRECTORY/tools/agbcc/lib/libgcc.a lib/libc.a

Finally, in the pmd-red directory, build the rom.

	make

# Windows

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Then get the compiled tools from https://github.com/pret/pokeruby-tools. Copy the `tools/` folder over the `tools/` folder in your pmd-red directory.

You can then build pmd-red using `make` in the MSYS environment provided with devkitARM.
=======

# Instructions

These instructions explain how to set up the tools required to build **pmd-red**, which assembles the source files into a ROM.

These instructions come with notes which can be expanded by clicking the "<i>Note...</i>" text.
In general, you should not need to open these unless if you get an error or if you need additional clarification.

If you run into trouble, ask for help on Discord or IRC (see [README.md](README.md)).

## Prerequisites 

First, you must put a Pokémon Mystery Dungeon Red Rescue Team 1.0 (US) ROM in the root directory of the repository and name it `baserom.gba`. It should have a SHA1 checksum of `9f4cfc5b5f4859d17169a485462e977c7aac2b89`. Then, follow the OS-specific instructions below:

- [Windows](#windows)
- [macOS](#macos)
- [Linux](#linux)

## Windows
- [Windows 10 (WSL1)](#windows-10-wsl1) (**Fastest, highly recommended**, Windows 10 only)

<details>
    <summary><i>Note for advanced users: <b>WSL2</b>...</i></summary>

>   <b>WSL2</b> is an option and is even faster than <b>WSL1</b> if files are stored on the WSL2 file system, but some tools may have trouble interacting
>   with the WSL2 file system over the network drive. For example, tools which use Qt versions before 5.15.2 such as <a href="https://github.com/huderlem/porymap">porymap</a>
>   may <a href="https://bugreports.qt.io/browse/QTBUG-86277">have problems with parsing the <code>\\wsl$</code> network drive path</a>.
</details>

All of the Windows instructions assume that the default drive is C:\\. If this differs to your actual drive letter, then replace C with the correct drive letter when reading the instructions.

**A note of caution**: As Windows 7 is officially unsupported by Microsoft and Windows 8 has very little usage, some maintainers are unwilling to maintain the Windows 7/8 instructions. Thus, these instructions may break in the future with fixes taking longer than fixes to the Windows 10 instructions.

## Windows 10 (WSL1)
WSL1 is the preferred terminal to build **pmd-red**. The following instructions will explain how to install WSL1 (referred to interchangeably as WSL).
- If WSL (Debian or Ubuntu) is **not installed**, then go to [Installing WSL1](#installing-wsl1).
- Otherwise, if WSL is installed, but it **hasn't previously been set up for another decompilation project**, then go to [Setting up WSL1](#setting-up-wsl1).
- Otherwise, **open WSL** and go to [Choosing where to store pmd-red (WSL1)](#choosing-where-to-store-pmd-red-wsl1).

### Installing WSL1
1. Open [Windows Powershell **as Administrator**](https://i.imgur.com/QKmVbP9.png), and run the following command (Right Click or Shift+Insert is paste in the Powershell).

    ```powershell
    dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
    ```

2. Once the process finishes, restart your machine.

3. The next step is to choose and install a Linux distribution from the Microsoft Store. The following instructions will assume Ubuntu as the Linux distribution of choice.
    <details>
        <summary><i>Note for advanced users...</i></summary>
    
    >   You can pick a preferred Linux distribution, but setup instructions may differ. Debian should work with the given instructions, but has not been tested. 
    </details>

4. Open the [Microsoft Store Linux Selection](https://aka.ms/wslstore), click Ubuntu, then click Get, which will install the Ubuntu distribution.
    <details>
        <summary><i>Notes...</i></summary>

    >   Note 1: If a dialog pops up asking for you to sign into a Microsoft Account, then just close the dialog.  
    >   Note 2: If the link does not work, then open the Microsoft Store manually, and search for the Ubuntu app (choose the one with no version number).
    </details>

### Setting up WSL1
Some tips before proceeding:
- In WSL, Copy and Paste is either done via
    - **right-click** (selection + right click to Copy, right click with no selection to Paste)
    - **Ctrl+Shift+C/Ctrl+Shift+V** (enabled by right-clicking the title bar, going to Properties, then checking the checkbox next to "Use Ctrl+Shift+C/V as Copy/Paste").
- Some of the commands that you'll run will ask for your WSL password and/or confirmation to perform the stated action. This is to be expected, just enter your WSL password and/or the yes action when necessary.

1. Open **Ubuntu** (e.g. using Search).
2. WSL/Ubuntu will set up its own installation when it runs for the first time. Once WSL/Ubuntu finishes installing, it will ask for a username and password (to be input in).
    <details>
        <summary><i>Note...</i></summary>

    >   When typing in the password, there will be no visible response, but the terminal will still read in input.
    </details>

3. Update WSL/Ubuntu before continuing. Do this by running the following command. These commands will likely take a long time to finish:

    ```bash
    sudo apt update && sudo apt upgrade
    ```

> Note: If the repository you plan to build has an **[older revision of the INSTALL.md](https://github.com/pret/pokeemerald/blob/571c598/INSTALL.md)**, then follow the [legacy WSL1 instructions](docs/legacy_WSL1_INSTALL.md) from here.

4. Certain packages are required to build pmd-red. Install these packages by running the following command:

    ```bash
    sudo apt install build-essential binutils-arm-none-eabi git libpng-dev
    ```
    <details>
        <summary><i>Note...</i></summary>

    >   If the above command does not work, try the above command but replacing `apt` with `apt-get`.
    </details>

### Choosing where to store pmd-red (WSL1)
WSL has its own file system that's not natively accessible from Windows, but Windows files *are* accessible from WSL. So you're going to want to store pmd-red within Windows.

For example, say you want to store pmd-red (and agbcc) in **C:\Users\\_\<user>_\Desktop\decomps**. First, ensure that the folder already exists. Then, enter this command to **change directory** to said folder, where *\<user>* is your **Windows** username:

```bash
cd /mnt/c/Users/<user>/Desktop/decomps
```

<details>
    <summary><i>Notes...</i></summary>

>   Note 1: The Windows C:\ drive is called /mnt/c/ in WSL.  
>   Note 2: If the path has spaces, then the path must be wrapped with quotations, e.g. `cd "/mnt/c/users/<user>/Desktop/decomp folder"`.  
>   Note 3: Windows path names are case-insensitive so adhering to capitalization isn't needed
</details>
    
If this works, then proceed to [Installation](#installation).

## macOS
1. If the Xcode Command Line Tools are not installed, download the tools [here](https://developer.apple.com/xcode/resources/), open your Terminal, and run the following command:

    ```bash
    xcode-select --install
    ```

2.  - If libpng is **not installed**, then go to [Installing libpng (macOS)](#installing-libpng-macos).
    - Otherwise, **open the Terminal** and go to [Choosing where to store pmd-red (macOS)](#choosing-where-to-store-pmd-red-macos)

### Installing libpng (macOS)
<details>
    <summary><i>Note for advanced users...</i></summary>

>   This guide installs libpng via Homebrew as it is the easiest method, however advanced users can install libpng through other means if they so desire.
</details>

1. Open the Terminal.
2. If Homebrew is not installed, then install [Homebrew](https://brew.sh/) by following the instructions on the website.
3. Run the following command to install libpng.

    ```bash
    brew install libpng
    ```
    libpng is now installed.

### Choosing where to store pmd-red (macOS)
At this point, you can choose a folder to store pmd-red into. If you're okay with storing pmd-red in the user folder, then proceed to [Installation](#installation). Otherwise, you'll need to account for where pmd-red is stored when changing directory to the pmd-red folder.

For example, if you want to store pmd-red (and agbcc) in **~/Desktop/decomps**, enter this command to **change directory** to the desired folder:
```bash
cd Desktop/decomps
```
Note that the directory **must exist** in the folder system. If you want to store pmd-red in a dedicated folder that doesn't exist (e.g. the example provided above), then create the folder (e.g. using Finder) before executing the `cd` command.

<details>
    <summary><i>Note..</i>.</summary>
    
>   Note: If the path has spaces, then the path must be wrapped with quotations, e.g. `cd "Desktop/decomp folder"`  
</details>

If this works, then proceed to [Installation](#installation). Otherwise, ask for help on Discord or IRC (see [README.md](README.md)).

## Linux
Open Terminal and enter the following commands, depending on which distro you're using.

### Debian/Ubuntu-based distributions
Run the following command to install the necessary packages:
```bash
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev
```
Then proceed to [Choosing where to store pmd-red (Linux)](#choosing-where-to-store-pmd-red-(linux)).

### Other distributions
_(Specific instructions for other distributions would be greatly appreciated!)_

1. Try to find the required software in its repositories:
    - `gcc`
    - `g++`
    - `make`
    - `git`
    - `libpng-dev`

### Choosing where to store pmd-red (Linux)
At this point, you can choose a folder to store pmd-red (and agbcc) into. If so, you'll have to account for the modified folder path when changing directory to the pmd-red folder.

If this works, then proceed to [Installation](#installation). Otherwise, ask for help on Discord or IRC (see [README.md](README.md)).

## Installation

<details>
    <summary><i>Note for Windows users...</i></summary>

>   Consider adding an exception for the `pmd-red` and/or `decomps` folder in Windows Security using
>   [these instructions](https://support.microsoft.com/help/4028485). This prevents Microsoft Defender from
>   scanning them which might improve performance while building.
</details>

1. If pmd-red is not already downloaded (some users may prefer to download pmd-red via a git client like GitHub Desktop), run:

    ```bash
    git clone https://github.com/pret/pmd-red
    ```

    <details>
        <summary><i>Note for WSL1...</i></summary>

    >   If you get an error stating `fatal: could not set 'core.filemode' to 'false'`, then run the following commands:
    >   ```bash
    >   cd
    >   sudo umount /mnt/c
    >   sudo mount -t drvfs C: /mnt/c -o metadata,noatime
    >   cd <folder where pmd-red is to be stored>
    >   ```
    >   Where *\<folder where pmd-red is to be stored>* is the path of the folder [where you chose to store pmd-red](#Choosing-where-to-store-pmd-red-WSL1). Then run the `git clone` command again.
    </details>

2. Install agbcc into pmd-red. The commands to run depend on certain conditions. **You should only follow one of the listed instructions**:
- If agbcc has **not been built before** in the folder where you chose to store pmd-red, run the following commands to build and install it into pmd-red:

    ```bash
    git clone https://github.com/pret/agbcc
    cd agbcc
    ./build.sh
    ./install.sh ../pmd-red
    ```

- **Otherwise**, if agbcc has been built before (e.g. if the git clone above fails), but was **last built on a different terminal** than the one currently used (only relevant to Windows, e.g. switching from msys2 to WSL1), then run the following commands to build and install it into pmd-red:

    ```bash
    cd agbcc
    git clean -fX
    ./build.sh
    ./install.sh ../pmd-red
    ```

- **Otherwise**, if agbcc has been built before on the same terminal, run the following commands to install agbcc into pmd-red:

    ```bash
    cd agbcc
    ./install.sh ../pmd-red
    ```

    <details>
        <summary><i>Note...</i></summary>

        > If building agbcc or pmd-red results in an error, try deleting the agbcc folder and re-installing agbcc as if it has not been built before.
    </details>

3. Once agbcc is installed, change directory back to the base directory where pmd-red and agbcc are stored:

    ```bash
    cd ..
    ```

Now you're ready to [build **pmd-red**](#build-pmd-red)
## Build pmd-red
If you aren't in the pmd-red directory already, then **change directory** to the pmd-red folder:
```bash
cd pmd-red
```
To build **pmd-red.gba** for the first time and confirm it matches the official ROM image (Note: to speed up builds, see [Parallel builds](#parallel-builds)):
```bash
make compare
```
If an OK is returned, then the installation went smoothly.
<details>
<summary>Note for Windows...</summary>
> If you switched terminals since the last build (e.g. from msys2 to WSL1), you must run `make clean-tools` once before any subsequent `make` commands.
</details>

To build **pmd-red.gba** with your changes:
```bash
make
```

# Building guidance

## Parallel builds

See [the GNU docs](https://www.gnu.org/software/make/manual/html_node/Parallel.html) and [this Stack Exchange thread](https://unix.stackexchange.com/questions/208568) for more information.

To speed up building, first get the value of `nproc` by running the following command:
```bash
nproc
```
Builds can then be sped up by running the following command:
```bash
make -j<output of nproc>
```
Replace `<output of nproc>` with the number that the `nproc` command returned.

`nproc` is not available on macOS. The alternative is `sysctl -n hw.ncpu` ([relevant Stack Overflow thread](https://stackoverflow.com/questions/1715580)).

## Other toolchains

To build using a toolchain other than devkitARM, override the `TOOLCHAIN` environment variable with the path to your toolchain, which must contain the subdirectory `bin`.
```bash
make TOOLCHAIN="/path/to/toolchain/here"
```
The following is an example:
```bash
make TOOLCHAIN="/usr/local/arm-none-eabi"
```
To compile the `modern` target with this toolchain, the subdirectories `lib`, `include`, and `arm-none-eabi` must also be present.

# Useful additional tools
* [Tilemap Studio](https://github.com/Rangi42/tilemap-studio) for viewing and editing tilemaps
>>>>>>> 386299d1f401cb939e6fe3ea16d0ca57731b2648

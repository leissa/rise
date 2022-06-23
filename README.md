# RISE in Thorin2

## Build Instructions

### Install Thorin

```sh
git clone --recurse-submodules git@github.com:AnyDSL/thorin2.git
cd thorin2
mkdir build
mkdir install
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=install
cmake --build build -j $(nproc) -t install
```

### Build Rise

```sh
cd ..
git clone git@github.com:leissa/rise.git
cd rise
mkdir build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -Dthorin_DIR=../thorin2/install/lib/cmake/thorin
cmake --build build -j $(nproc)
```

## Run

```sh
TODO
```

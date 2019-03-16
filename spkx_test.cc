#include "spk/presenter.h"
#include "spk/program.h"

int main(int argc, char** argv) {
  spkx::program program(argc, argv);
  spkx::presenter presenter(program.physical_device(), program.window(),
                            program.surface(), program.device());
}

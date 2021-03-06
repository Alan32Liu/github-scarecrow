#include <string>
extern "C" {
  #include <string.h>
}

std::string constructEchoCommand(const char *data, size_t size) {
  return std::string("echo ") + '"' + std::string(data, size) + '"';
}


extern "C" int LLVMFuzzerTestOneInput(const char *data, size_t size) {
  if (data == NULL || size <= 0) {
    return 0;
  }
  system(constructEchoCommand(data, size).c_str());
  return 0;
}


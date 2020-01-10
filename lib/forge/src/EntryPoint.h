#pragma once

//#ifdef FRG_PLATFORM_WINDOWS

extern forge::Application *forge::CreateApplication();

int main(int argc, char **argv) {

  printf("test\n");
  forge::Application *app = forge::CreateApplication();

  app->Run();

  delete app;

  return 0;
}

//#endif
#include <forge.h>

class TerraGenApplication : public forge::Application
{
  public:
	TerraGenApplication() {}
	~TerraGenApplication() {}
};

forge::Application* forge::CreateApplication() { return new TerraGenApplication(); }

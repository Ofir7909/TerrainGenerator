#pragma once

extern forge::Application* forge::CreateApplication();

int main(int argc, char** argv)
{
	forge::Log::Init();
	FRG_CORE_WARN("Initalizing Application");

	forge::Application* app = forge::CreateApplication();

	app->Run();

	delete app;
}
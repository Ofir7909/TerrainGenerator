#include "LayerStack.h"

forge::LayerStack::LayerStack() { m_LayerInsert = this->begin(); }

forge::LayerStack::~LayerStack()
{
	for (Layer* layer : m_Layers) delete layer;
}

void forge::LayerStack::PushLayer(Layer* layer)
{
	m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
}

void forge::LayerStack::PushOverlay(Layer* layer) { m_Layers.emplace_back(layer); }

void forge::LayerStack::PopLayer(Layer* layer)
{
	auto it = std::find(this->begin(), this->end(), layer);
	if (it != this->end()) {
		m_Layers.erase(it);
		m_LayerInsert--;
	}
}

void forge::LayerStack::PopOverlay(Layer* layer)
{
	auto it = std::find(this->begin(), this->end(), layer);
	if (it != this->end()) {
		m_Layers.erase(it);
	}
}

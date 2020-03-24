#include "LayerStack.h"

namespace forge
{
LayerStack::LayerStack() { m_LayerInsert = this->begin(); }

LayerStack::~LayerStack()
{
	for (Layer* layer : m_Layers) delete layer;
}

void LayerStack::PushLayer(Layer* layer) { m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer); }

void LayerStack::PushOverlay(Layer* layer) { m_Layers.emplace_back(layer); }

void LayerStack::PopLayer(Layer* layer)
{
	auto it = std::find(this->begin(), this->end(), layer);
	if (it != this->end()) {
		m_Layers.erase(it);
		m_LayerInsert--;
	}
}

void LayerStack::PopOverlay(Layer* layer)
{
	auto it = std::find(this->begin(), this->end(), layer);
	if (it != this->end()) {
		m_Layers.erase(it);
	}
}
} // namespace forge

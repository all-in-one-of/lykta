#pragma once

#include <vector>
#include <string>
#include <glm/vec3.hpp>
#include "Integrator.hpp"
#include "Scene.hpp"
#include "random.h"

namespace Lykta {
	class Renderer {
	private:
		std::vector<glm::vec3> image;
		std::shared_ptr<Scene> scene;
		std::unique_ptr<Integrator> integrator;
		Integrator::Type integratorType;
		std::vector<RandomSampler> samplers;
		glm::ivec2 resolution;
		unsigned iteration;

	public:
		void openScene(const std::string& filename);
		void refresh();
		
		void renderFrame();

		const std::vector<glm::vec3>& getImage() const {
			return image;
		}

		const glm::ivec2& getResolution() const {
			return resolution;
		}

		void changeIntegrator(Integrator::Type type) {
			integratorType = type;
		}

	};
}
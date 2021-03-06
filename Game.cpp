#include "Game.h"

using namespace brkr;

Game::Game() : TIMESTEP(sf::milliseconds(333)), m_currentState(std::make_unique<InitState>())
{
}

void Game::run()
{
	m_running = true;
	sf::Clock clk;
	sf::Time timeDeposit;

	while (m_running)
	{
		timeDeposit += clk.restart();
		while (timeDeposit >= TIMESTEP)
		{
			update(TIMESTEP);
			timeDeposit -= TIMESTEP;
		}

		m_currentState->draw();
	}
}


void Game::update(sf::Time dt)
{
	auto state = m_currentState->update(dt);
	if (state == nullptr)
	{
		m_running = false;
	} else if (state != m_currentState.get()) {
		m_currentState.reset(state);
	} 
}



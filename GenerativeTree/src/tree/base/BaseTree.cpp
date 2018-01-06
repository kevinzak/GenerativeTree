#include "BaseTree.h"

#include "cinder/Log.h"
#include <ctime>

#include "bluecadet/utils/ImageManager.h"
#include "bluecadet/core/SettingsManager.h"
#include "bluecadet/core/ScreenLayout.h"

#include "bluecadet/views/AnimatedView.h"
#include "bluecadet/views/TextView.h"

#include "../../core/GenerativeTreeSettingsManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::core;
using namespace bluecadet::views;
using namespace bluecadet::utils;

namespace genApp {

	BaseTree::BaseTree() : BaseView() {
	}

	BaseTree::~BaseTree() {
	}

	void BaseTree::setup() {
		// Configure canvas
		setSize(vec2(200,ScreenLayout::getInstance()->getAppHeight()));
		setBackgroundColor(Color(1, 0, 0));

		// Setup Views
		mTestBranch = make_shared<BaseBranch>();
		mTestBranch->setup();
		//mTestBranch->setRotation(1.5708);
		//addChild(mTestBranch);
	
		generateBranches(4, 4);
	}

	//==================================================
	// Setup helpers
	// 
	void BaseTree::generateBranches(const int min, const int max) {
		srand(time(NULL));
		int numOfBranches = (rand() % max) + min;
		for (int i = 0; i < numOfBranches; i++) {
			BaseBranchRef newBranch = make_shared<BaseBranch>();
			newBranch->setup();
			float xPos = 0;
			float yPos = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / ((getHeight() * 0.8f) - 0))); // Generate branches on the top 80% of the tree
			newBranch->setPosition(vec2(xPos, yPos));
			newBranch->setRotation(1.5708);
			addChild(newBranch);
		}
		
	}


	//==================================================
	// Setup helpers
	// 

	void BaseTree::setupParams() {

	}

}

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/BaseView.h"
#include "bluecadet/views/ImageView.h"
#include "bluecadet/views/TouchView.h"

#include "BaseBranch.h"
namespace genApp {

	typedef std::shared_ptr<class BaseTree> BaseTreeRef;

	class BaseTree : public bluecadet::views::BaseView {

	public:

		BaseTree();
		~BaseTree();

		void	setup();

	protected:
		// Functions
		void	setupParams();
		void	generateBranches(const int min, const int max);
		// Views
		// TODO: Add Branches
		BaseBranchRef mTestBranch;
		BaseBranchRef mTestBranch_1;


	};
}

#include <QtQuick/qsgflatcolormaterial.h>
#include <QtMath>

#include "link.h"
#include "views/output.h"
#include "views/input.h"
#include "views/genericnode.h"
#include "views/dulycanvas.h"
#include "controllers/outputcontroller.h"

namespace duly_gui
{
	namespace views
	{
		Output::Output(QQuickItem *parent) :
			Io(parent)

		{
			m_linkable = new controllers::OutputController(m_type, this);
		}

		void Output::refreshBackendIo()
		{
			m_linkable = new controllers::OutputController(m_type, this);
		}

		void Output::componentComplete()
		{
			QQuickItem::componentComplete();
			auto n = dynamic_cast<GenericNode *>(parentItem()->parentItem()->parentItem()->parentItem()->parentItem());
			n->outputs().registerItem(this);
		}

		LinkableBezierItem* Output::findLinkableBezierItem(class GenericNode* n, const QPointF& p)
		{
			auto qlist = n->inputs().findFocused(p);
			return (qlist.size() != 0) ? dynamic_cast<Io*>(qlist.at(0)) : nullptr;
		}

		void Output::updateLink()
		{
			auto list = m_linkable->links();
			for (auto i = 0; i < list.size(); i++)
			{
				const auto l = list.at(i);
				l->curve()->setRealPosition(getCanvasPos());
				const auto io = dynamic_cast<Input *>(dynamic_cast<BaseIo *>(l->L1 != m_linkable ? l->L1 : l->L2)->parent());
				l->curve()->setP4(io->getCanvasPos());
			}
		}
	}
}

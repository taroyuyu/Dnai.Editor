#ifndef MODEL_INPUT_H
#define MODEL_INPUT_H

#include "models/variable.h"
#include "models/identity.h"
#include "models/imodel.h"

namespace duly_gui {
    namespace models {
        class Input: public Variable, Identity, virtual public IModel
        {
        public:
            Input(QString const &, QString const &, QString const &, bool, QString const &, QString const &);
            virtual ~Input();

            // IModel interface
        public:
            virtual void serialize(QJsonObject &) const;

            // IClone interface
        private:
            IClone *clone() const;
        };
    }
}

#endif // MODEL_INPUT_H

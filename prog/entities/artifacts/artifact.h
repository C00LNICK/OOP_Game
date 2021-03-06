#ifndef GAME_ARTIFACT_H
#define GAME_ARTIFACT_H

#include <functional>

#include "../../../lib/containers/vector/Vector.h"

#include "../entity.h"

class character; // pre-declaration

class artifact : public entity {

public:

    using artifact_action = std::function<void(character*)>;

    enum artifact_id {
        PROTEIN = 0,
        APPLE,
        GOLDEM_APPLE,
        KNIFE,

        COUNT
    };

    struct artifact_info {
        const char* m_name;
        int m_id;
        artifact_action m_action;
        artifact_action m_reaction;
    };

private:

    static const Vector<artifact_info> artifact_infos;

    artifact_id m_id;

public:

    artifact(artifact_id id, geo::i_point coords = { -1, -1 });

    artifact_id id() const;

    static void act(artifact* art, character* ch);
    static void react(artifact* art, character* ch);

    void save(std::ostream &out) const override;
    void load(std::istream &in) override;
};

#endif //GAME_ARTIFACT_H
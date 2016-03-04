#include "QuoridorConsole.h"

QuoridorConsole::QuoridorConsole(string n1, string n3, unsigned size)
    : game_(n1, n3, size)
{
    game_.registerObserver(this);
}

QuoridorConsole::QuoridorConsole(string n1, string n2, string n3, string n4, unsigned size)
    : game_(n1, n2, n3, n4, size)
{
    game_.registerObserver(this);
}

QuoridorConsole::~QuoridorConsole()
{
    game_.unregisterObserver(this);
}

void QuoridorConsole::update(const Subject *subject)
{
    if (subject!=&game_) return;
    cout << game_.getBoard().toString() << endl;
}

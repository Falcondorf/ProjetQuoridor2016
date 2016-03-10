#ifndef TEST
#define TEST
class Test{

public:

    static void runTest();
private:

//classe Player
    static void TestPlayerCase1();
    static void TestPlayerCase2();
    static void TestPlayerCase3();
    static void TestPlayerWallStock();
    static void TestPlayerPosition();
    static void TestPickWall();
    static void TestPlayerConstrFail();
    static void TestPlayerConstrFail2();
    static void TestPlayerConstrOk();
    static void TestHasWonSetwin();   
    static void TestGetName();
    static void TestGetNum();
//classe Frame
    static void TestFrameSide();
    static void TestFrameSide2();
    static void TestFramePrintContent();
    static void FrameFailConstrP();
    static void TestFramePPlace();
    static void TestFrameWPlace();
    static void TestFrameWEmpty();
//classe Board
    static void TestBoardCreateOK();
    static void TestBoardCreateKO();
    static void TestBoardIsFree();
    static void TestBoardIsFree2();
    static void TestFindPath();
    static void TestFindPathBlocked();
    static void TestFindPathFig4();
    static void TestEvalPosition();
    static void TestPlaceBoard();
    static void TestPlaceBoardFail();
    static void TestIsOverWinGame();
    static void TestBoardEmptyWall();
    static void TestBoardEmptyWallFail();
    static void TestGetlen();    
//classe Side
    static void TestSideToString();

//classe Game
    static void TestGameConstr();
    static void TestGameConstrFail();
    static void TestGameNbPlayer();
    static void TestGetCurrentPlayerAndName();
    static void TestGameMove();
    static void TestVictoryCond();
    static void TestPlayWall();

};

#endif // TEST


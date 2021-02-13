#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        virtual ~Player();
        void callInput();
        void resetPosition();
        int x ,y;
        int lastX, lastY;
    protected:
    private:
};

#endif // PLAYER_H

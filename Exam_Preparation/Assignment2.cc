#include <iostream>

using namespace std;


class Chess_Piece {
public:
    Chess_Piece(int file, char rank) : file{file}, rank{rank} {

    }
    ~Chess_Piece() = default;

    virtual bool valid_move(int file, char rank) const = 0;

protected:
    void correct_positions(int file, char rank) const;
    int file{};
    char rank{};
};

class Pawn : public Chess_Piece {
public:
    Pawn(int file, char rank) : Chess_Piece{file, rank} {}
    bool valid_move(int file, char rank) const;
};

class Rook : public Chess_Piece {
public:
    Rook(int file, char rank) : Chess_Piece{file, rank} {}
    bool valid_move(int file, char rank) const;
};

class Queen : public Rook {
public:
    Queen(int file, char rank) : Rook{file, rank} {}
    bool valid_move(int file, char rank) const;
};

void Chess_Piece::correct_positions(int file, char rank) const {
    if (file < 1 || file > 8)
        throw runtime_error("file outside range");
    if (rank < 'A' || rank > 'H') {
        throw runtime_error("rank outside range");
    }
}

bool Pawn::valid_move(int file, char rank) const {
    correct_positions(file, rank);
    if (rank != this->rank) return false;
    if (file == 2) {
        return file == 3 || file == 4;
    };
    return this->file + 1 == file;
}

bool Rook::valid_move(int file, char rank) const {
    correct_positions(file, rank);
    return file == this->file || rank == this->rank;
}

bool Queen::valid_move(int file, char rank) const {
    correct_positions(file, rank);
    return Rook::valid_move(file, rank) || 
        (abs(this -> file - file) == abs(this -> rank - rank));
}

int main() {
    Chess_Piece const& pawn{Pawn{2, 'A'}};
    if (pawn.valid_move(3, 'A')) {
        cout << "correct" << endl;
    }
    Chess_Piece const& rook{Rook{3, 'D'}};
    if (rook.valid_move(3, 'F')) {
        cout << "correct" << endl;
    }
    Chess_Piece const& queen{Queen{3, 'D'}};
    if (queen.valid_move(2, 'E')) {
        cout << "correct" << endl;
    }
}
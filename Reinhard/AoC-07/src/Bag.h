

class Bag
{
public:
    Bag();
    ~Bag();

    // My own ID
    string m_ID;                 // I am a xy - colored bag

    // Containers
    vector <int>    m_nBags;     // number of that container
    vector <string> m_BagsID;    // ID of that conatainer
};
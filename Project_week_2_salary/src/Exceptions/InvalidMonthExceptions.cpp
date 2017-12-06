#include "InvalidMonthExceptions.h"

InvalidMonthExceptions::InvalidMonthExceptions()
{
    //ctor
}

InvalidMonthExceptions::InvalidMonthExceptions(string message)
{
    this->message = message;
}

void InvalidMonthExceptions::print_message()
{
    cout << this->message << endl;
}

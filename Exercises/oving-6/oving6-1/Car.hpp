//
//  Car.hpp
//  oving6
//
//  Created by Gjert Ingar Gjersund on 22.02.2018.
//  Copyright © 2018 Gjert Ingar Gjersund. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

class Car {
    private:
        int freeSeats;
    public:
        Car(int seats);
        bool hasFreeSeats() const;
        void reserveFreeSeat();
};

#endif /* Car_hpp */

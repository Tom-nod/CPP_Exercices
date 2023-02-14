#pragma once

#include <string>
#include <memory>
#include <utility>

class Trainer;

#define PokemonPtr std::unique_ptr<Pokemon>

// A creature that is cute and can fight other ones.
class Pokemon{
    public:
        Pokemon(const Pokemon& pokemon)
        :_name(pokemon._name), _id(pokemon.next_id++){
            
        }

        Pokemon(std::string name)
        :_name(name), _id(next_id++){
        }

        const std::string name() const {
            return _name;
        }

        int id() const {
            return _id;
        }
        
        Pokemon& operator=(const Pokemon& pokemon){
            if(this == &pokemon){
                _name = pokemon._name;
            }
            return *this;
        }

        Trainer* trainer() const{
            return _trainer;
        }

        void set_trainer(Trainer& trainer){
            _trainer = &trainer;
        }

    private:
        static int next_id;
        std::string         _name;
        int                 _id;
        Trainer*            _trainer = nullptr;
};

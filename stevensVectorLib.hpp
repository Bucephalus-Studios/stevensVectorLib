#include<algorithm>
#include<numeric>


namespace stevensVectorLib
{
    /*** Methods ***/
    /**
     * Given a vector of objects T vec, and an eraseTarget of type T, erase all instances of the eraseTarget 
     * from vec, then return vec.
     * 
     * Parameters:
     *  std::vector<T> vec - The vector we are erasing all of an eraseTarget from.
     *  T eraseTarget - The thing we are erasing all occurrences of in vec.
     * 
     * Returns:
     *  std::vector<T> - The modified vector vec with all instances of eraseTarget erased from it.
    */
    template<typename T>
    std::vector<T> eraseAll(    std::vector<T> vec,
                                T eraseTarget)
    {
        vec.erase(std::remove(vec.begin(), vec.end(), eraseTarget), vec.end());
        return vec;
    }


    /**
     * Sum all of the elements in the vector and returns the result.
     * 
     * Parameters:
     *  std::vector<T> vec - A vector of elements of type T that can be added together.
     *  T init - The initial value we will begin adding to for our sum.
     * 
     * Returns:
     *  T - Object of type T of all of the vector elements summed together.
    */
    template<typename T>
    T sumAll(   std::vector<T> vec,
                T init  )
    {
        return accumulate(vec.begin(), vec.end(), init);
    }


    /**
     * Multiply all elements in the vector and return the result.
     * 
     * Parameters:
     *  std::vector<T> vec - A vector of elements of type T that can be multiplied together.
     *  T init - A number we will multiply our product by. Default is 1.
     * 
     * Returns:
     *  T - Object of type T of the product of all vector elements multiplied together.
    */
    template<typename T>
    T multiplyAll(  std::vector<T> vec,
                    T init = 1 )
    {
        return std::accumulate(std::begin(vec), std::end(vec), init, std::multiplies<>());
    }


    /**
     * Given a std::vector<std::string>, returns a std::vector<int>, where all std::strings in the original vector are converted to integers
     * that they represent.
     * 
     * May throw error with std::stoi if the parameter vector contains an string that does not properly represent an integer.
     * 
     * Taken from:
     * https://stackoverflow.com/a/15619863/16511184
     * 
     * Parameter:
     *  std::vector<std::string> inputVec - A vector of std::strings, where each string represents an integer, which we wish to convert into a std::vector<int>.
     * 
     * Returns:
     *  std::vector<int> - Our parameter vector, but all of its elements converts to the ints.
    */
    std::vector<int> vecOfStrings_to_vecOfInts( std::vector<std::string> inputVec)
    {
        std::vector<int> outputVec = {};

        std::transform(inputVec.begin(), inputVec.end(), std::back_inserter(outputVec),
                [](const std::string& str) { return std::stoi(str); });

        return outputVec;
    }

    
    std::vector<long long int> vecOfStrings_to_vecOfLongLongInts( std::vector<std::string> inputVec)
    {
        std::vector<long long int> outputVec = {};

        std::transform(inputVec.begin(), inputVec.end(), std::back_inserter(outputVec),
                [](const std::string& str) { return std::stoll(str); });

        return outputVec;
    }


    /**
    * Given a vector of type T, vec, return the minimum element contained within it.
    * 
    * Parameter:
    *  std::vector<T> vec - A vector with elements of type T.
    * 
    * Returns:
    *  T - The minimum element of vec
    */
    template<typename T>
    T findMin( const std::vector<T> vec)
    {
        //Throw an error if the vector is empty
        if(vec.empty())
        {
            std::cerr << "stevensVectorLib Error: findMin(): Parameter must be a vector with size greater than 0" << std::endl;
            exit(EXIT_FAILURE);
        }

        return *min_element(std::begin(vec), std::end(vec));
    }


    /**
     * @brief Given a vector, return a random element from it.
     * 
     * Credit: https://stackoverflow.com/a/44577004/16511184
     * 
     * @tparam T The type of element stored in the vector.
     * @param vec The vector we wish to have a random element returned from it.
     * @return T A random element from vec.
     */
    template<typename T>
    T getRandomElement( const std::vector<T> & vec  )
    {
        //If there are no elements, throw an error
        if(vec.size() == 0)
        {
            throw std::invalid_argument("stevensVectorLib::getRandomElement() cannot get a random element from an empty vector");
        }

        int randomPos = std::rand() % vec.size();  // Modulo to restrict the number of random values to be at most vec.size()-1
        return vec[randomPos];
    }


    /**
     * @brief Given two vectors, vec_a and vec_b, combine them into a single vector where order is preserved such
     *        that vec_b's first element appears right after vec_a's final element in the resulting vector.
     * 
     * Credit to Stepan Yakovenko https://stackoverflow.com/a/33649647/16511184
     * 
     * @tparam T The element type contained within the vector we are concatenating.
     * @param vec_a The vector that vec_b will be concatenated onto the end of.
     * @param vec_b The vector that will be concatenated onto the end of vec_a.
     * 
     * @return A vector containing all of then elements of vec_a and all of the elements of vec_b in that order.
     */
    template<typename T>
    std::vector<T> concat(  const std::vector<T> & vec_a,
                            const std::vector<T> & vec_b    )
    {
        std::vector<T> vec_ab;
        std::copy(vec_a.begin(), vec_a.end(), std::back_inserter(vec_ab));
        std::copy(vec_b.begin(), vec_b.end(), std::back_inserter(vec_ab));
        return vec_ab;
    }
}
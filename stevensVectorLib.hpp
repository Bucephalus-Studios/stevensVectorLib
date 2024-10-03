#include<algorithm>
#include<numeric>


namespace stevensVectorLib
{
    /*** Methods ***/

    /**
     * @brief Check to see if a vector contains a certain element.
     * 
     * @param vec The vector we are checking to see if it contains a certain element.
     * @param element The element we are checking to see if it is in vec.
     * 
     * @return True if vec contains element. False otherwise.
     */
    template<typename T>
    bool contains(  std::vector<T> vec,
                    T element   )
    {
        if(std::find(vec.begin(), vec.end(), element) != vec.end())
        {
            return true;
        }
        return false;
    }


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
    std::vector<T> eraseAllOf(    std::vector<T> vec,
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
     * @tparam T The element type contained within the vectors we are concatenating.
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


    /**
     * @brief Given two vectors, vec_a and vec_b, return a vector containing all of the elements they don't hold in common.
     * 
     * @tparam T The element type contained within the vec_a and vec_b
     * @param vec_a A vector we want to include the elements of i nthe returned vector that are not included in vec_b
     * @param vec_b A vector we want to include the elements of in the returned vector that are not included in vec_a
     * 
     * @return A vector containing all of the elements in vec_a and vec_b that they don't have in common.
     */
    template<typename T>
    std::vector<T> getUncommonElements(     std::vector<T> & vec_a,
                                            std::vector<T> & vec_b    )
    {
        std::vector<T> vec_c; //The vector that we'll be returning which contains the uncommon elements of vec_a and vec_b

        //Put the elements into vec_c that are in vec_a, but not vec_b
        for(int i = 0; i < vec_a.size(); i++)
        {
            //Search vec_b to see if it does not contain the element in vec_a
            if(!vec_b.find(vec_a[i]))
            {
                //If vec_b does not contain the element in vec_a, push it back into vec_c
                vec_c.push_back(vec_a[i]);
            }
        }
        //Put the elements into vec_c that are in vec_b, but not vec_a
        for(int i = 0; i < vec_b.size(); i++)
        {
            //Search vec_a to see if it does not contain the element in vec_b
            if(!vec_a.find(vec_b[i]))
            {
                //If vec_a does not contain the element in vec_b, push it back into vec_c
                vec_c.push_back(vec_b[i]);
            }
        }

        return vec_c;
    }


    /**
     * @brief Given a 2D vector containing elements of type T named vecOfVecs, return the vector from vecOfVecs
     *        that is the greatest in size. If there is a tie for the vector with greatest size, we will always
     *        return the vector that we saw the earliest in the search process.
     * 
     * @tparam T 
     * @param vecOfVecs The 2D vector we are searching to find and return the largest vector within it.
     * @param searchFrom A string describing from which side of the vector we will begin searching from. 
     *                   Valid values are "beginning" and "end"
     * @return The vector from vecOfVecs that is the greatest in size
     */
    template<typename T> 
    std::vector<T> getLargestVectorElement( const std::vector< std::vector<T> > & vecOfVecs,
                                            const std::string & searchFrom = "beginning" )
    {
        //If the vecOfVecs is empty, we throw an error
        if(vecOfVecs.empty())
        {
            throw std::invalid_argument("stevensVectorLib::getLargestVectorElement() error: Given vecOfVecs parameter is empty");
        }

        //Iterate through vecOfVecs, keeping track of the index of the vector that has the greatest size
        unsigned long long int indexOfGreatestSizeVector = 0;
        if(searchFrom == "beginning")
        {
            for(unsigned long long int i = 0; i < vecOfVecs.size(); i++)
            {
                if(vecOfVecs[i].size() > vecOfVecs[indexOfGreatestSizeVector].size())
                {
                    indexOfGreatestSizeVector = i;
                }
            }
        }
        else
        {
            for(unsigned long long int i = (vecOfVecs.size() - 1); i >= 0; i--)
            {
                if(vecOfVecs[i].size() > vecOfVecs[indexOfGreatestSizeVector].size())
                {
                    indexOfGreatestSizeVector = i;
                }
            }
        }

        return vecOfVecs[indexOfGreatestSizeVector];
    }


    /**
     * @brief Given a vector of stringlike objects, search the vector for the longest string element
     *        and return it. If there is a tie for the longest string element, we always return 
     *        the string we saw earlier in the search process.
     * 
     * @tparam T the stringlike element type that vec contains
     * @param vec The vector that we are searching for the longest stringlike element
     * @param searchFrom A string describing from which side of the vector we will begin searching from. 
     *                   Valid values are "beginning" and "end"
     * @return The string of greatest length from vec
     */
    template<typename T>
    T getLongestStringElement(  const std::vector<T> & vec,
                                const std::string & searchFrom = "beginning"    )
    {
        //If vec is empty, we throw an error
        if(vec.empty())
        {
            throw std::invalid_argument("stevensVectorLib::getLongestStringElement() error: Given vec parameter is empty");
        }

        //Iterate through vec, keeping track of the index of the string that has the greatest length
        unsigned long long int indexOfLongestString = 0;
        if(searchFrom == "beginning")
        {
            for(unsigned long long int i = 0; i < vec.size(); i++)
            {
                if(vec[i].length() > vec[indexOfLongestString].length())
                {
                    indexOfLongestString = i;
                }
            }
        }
        else
        {
            for(unsigned long long int i = (vec.size() - 1); i >= 0; i--)
            {
                if(vec[i].length() > vec[indexOfLongestString].length())
                {
                    indexOfLongestString = i;
                }
            }
        }

        return vec[indexOfLongestString];
    }


    /**
     * @brief Given a two-dimensional vector, reorient the grouping of elements in the vector such
     *        that the resulting vector contains vectors of elements that all share the same index 
     *        in their original vector.
     * 
     *        Example:
     *        inputTable = {    {"Name", "Age", "Power"},
     *                          {"Kelsier", "34", "Mistborn"},
     *                          {"Marsh", "36", "Seeker"},
     *                          {"Vin", "19", "Mistborn"}   };
     * 
     *        outputTable = reorient2DVector(inputTable);
     *         
     *        outputTable == {  {"Name", "Kelsier", "Marsh", "Vin"},
     *                          {"Age", "34", "36", "19"},
     *                          {"Power", "Mistborn", "Seeker", "Mistborn"}  }
     * 
     * @tparam T The type of elements that the 2D vector is storing
     * @param inputVecOfVecs A 2D vector that we wish to reorient the grouping of its elements.
     * @return The inputVecOfVecs parameter by regrouped as described by the example above..
     */
    template<typename T>
    std::vector< std::vector<T> > reorient2DVector( const std::vector< std::vector<T> > & inputVecOfVecs )
    {
        std::vector< std::vector<T> > outputVecOfVecs;

        //Get the vector of greatest size from the inputVecOfVecs and use its size to determine the number of vectors the outputVecOfVecs should contain
        unsigned long long int outputVecOfVecsSize = stevensVectorLib::getLargestVectorElement(inputVecOfVecs).size();
        outputVecOfVecs.resize(outputVecOfVecsSize);

        //Iterate through the inputVecOfVecs, pushing elements the outputVecOfVecs in the correct places
        for(int row = 0; row < inputVecOfVecs.size(); row++)
        {
            for(int col = 0; col < inputVecOfVecs[row].size(); col++)
            {
                outputVecOfVecs[col].push_back(inputVecOfVecs[row][col]);
            }
        }

        return outputVecOfVecs;
    }


    /**
     * @brief Given a vector of elements of type T, erase any instances of duplicate elements that exist such that
     *        any duplicate elements that occur in the vector after the first instance will be erased. The order of the
     *        vector elements will be maintained.
     * 
     *        Example: vec = {1,2,1,3,4,4,5,1};
     *                 removeDuplicateElements(vec);
     *                 //vec == {1,2,3,4,5}
     * 
     * @param vec The vector that will have duplicate elements erased from it.
     * 
     * @return The modified input parameter vec with all of its duplicated elements erased.
     */
    template<typename T>
    std::vector<T> eraseDuplicateElements( std::vector<T> vec  )
    {
        //Create a vector that will have the elements of vec in order with no duplicates
        std::vector<T> returnVec;
        for(int i = 0; i < vec.size(); i++)
        {
            //Only push back elements from vec that aren't already in returnVec
            if(!stevensVectorLib::contains(returnVec, vec[i]))
            {
                returnVec.push_back(vec[i]);
            }
        }
        return returnVec;
    }


    /**
     * @brief Given two vectors vec_a and vec_b, return a vector that is a modified vec_a with all of the elements held in common with
     *        vec_b having been erased from it.
     * 
     *        Example: vec_a = {1,1,2,3,4,5};
     *                 vec_b = {1,3,5};
     *                 result_vec = stevensVectorLib::difference(vec_a,vec_b);
     *                 //result_vec == {1,2,4}
     * 
     * @param vec_a The vector we are erasing elements from.
     * @param vec_b The vector containing the elements and their quantities we are erasing from vec_a.
     * 
     * @return vec_a but with all of the elements in vec_b erased from it.
     */
    template<typename T>
    std::vector<T> difference(  std::vector<T> vec_a,
                                const std::vector<T> & vec_b )
    {
        //For each element in vec_b, find it and erase it from vec_a
        for(int i = 0; i < vec_b.size(); i++)
        {
            //Find the position of the element to erase
            auto it = std::find(vec_a.begin(), vec_a.end(), vec_b[i]); 
            //If the element was found
            if(it != vec_a.end())
            {
                //Erase the element
                vec_a.erase(it);
            }
        }
        return vec_a;
    }
}
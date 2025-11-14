#ifndef STEVENS_VECTOR_LIB_HPP
#define STEVENS_VECTOR_LIB_HPP

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>
#include <string>
#include <limits>
#include <unordered_set>
#include <cstdlib>

namespace stevensVectorLib
{
    /**
     * @brief Check if a vector contains a specific element.
     *
     * @param vec The vector to search.
     * @param element The element to find.
     * @return true if vec contains element, false otherwise.
     */
    template<typename T>
    bool contains(const std::vector<T>& vec, const T& element)
    {
        return std::find(vec.begin(), vec.end(), element) != vec.end();
    }


    /**
     * @brief Erase all instances of a target element from a vector.
     *
     * @param vec The vector to modify.
     * @param eraseTarget The element to erase from vec.
     */
    template<typename T>
    void eraseAllOf(std::vector<T>& vec, const T& eraseTarget)
    {
        vec.erase(std::remove(vec.begin(), vec.end(), eraseTarget), vec.end());
    }


    /**
     * @brief Sum all elements in a vector.
     *
     * @param vec A vector of elements that can be added together.
     * @param init The initial value for the sum.
     * @return The sum of all vector elements plus init.
     */
    template<typename T>
    T sumAll(const std::vector<T>& vec, T init = T{})
    {
        return std::accumulate(vec.begin(), vec.end(), init);
    }


    /**
     * @brief Multiply all elements in a vector.
     *
     * @param vec A vector of elements that can be multiplied together.
     * @param init The initial value for the product. Default is 1.
     * @return The product of all vector elements.
     */
    template<typename T>
    T multiplyAll(const std::vector<T>& vec, T init = T{1})
    {
        return std::accumulate(vec.begin(), vec.end(), init, std::multiplies<T>());
    }


    /**
     * @brief Convert a vector of string-like objects to a vector of the target type.
     *
     * @tparam TargetType The numeric type to convert to.
     * @tparam StringType The string-like type (e.g., std::string).
     * @tparam Converter The conversion function type.
     * @param inputVec A vector of strings representing numbers.
     * @param converter A function to convert strings to the target type.
     * @return A vector of converted values.
     * @throws std::invalid_argument if conversion fails.
     */
    template<typename TargetType, typename StringType, typename Converter>
    std::vector<TargetType> convertStringVector(const std::vector<StringType>& inputVec, Converter converter)
    {
        std::vector<TargetType> outputVec;
        outputVec.reserve(inputVec.size());
        std::transform(inputVec.begin(), inputVec.end(), std::back_inserter(outputVec), converter);
        return outputVec;
    }


    /**
     * @brief Convert a vector of strings to a vector of integers.
     *
     * @param inputVec A vector of strings, where each represents an integer.
     * @return A vector of integers.
     * @throws std::invalid_argument if any string cannot be converted.
     */
    inline std::vector<int> vecOfStrings_to_vecOfInts(const std::vector<std::string>& inputVec)
    {
        return convertStringVector<int>(inputVec, [](const std::string& str) { return std::stoi(str); });
    }


    /**
     * @brief Convert a vector of strings to a vector of long long integers.
     *
     * @param inputVec A vector of strings, where each represents a long long integer.
     * @return A vector of long long integers.
     * @throws std::invalid_argument if any string cannot be converted.
     */
    inline std::vector<long long> vecOfStrings_to_vecOfLongLongInts(const std::vector<std::string>& inputVec)
    {
        return convertStringVector<long long>(inputVec, [](const std::string& str) { return std::stoll(str); });
    }


    /**
     * @brief Find the first index at which an element occurs in a vector.
     *
     * @param vec The vector to search.
     * @param element The element to find.
     * @return The index of the first occurrence, or std::numeric_limits<size_t>::max() if not found.
     */
    template<typename T>
    size_t findElementIndex(const std::vector<T>& vec, const T& element)
    {
        auto it = std::find(vec.begin(), vec.end(), element);
        return (it != vec.end()) ? std::distance(vec.begin(), it) : std::numeric_limits<size_t>::max();
    }


    /**
     * @brief Find the minimum element in a vector.
     *
     * @param vec A non-empty vector.
     * @return The minimum element.
     * @throws std::invalid_argument if vec is empty.
     */
    template<typename T>
    T findMin(const std::vector<T>& vec)
    {
        if (vec.empty())
        {
            throw std::invalid_argument("stevensVectorLib::findMin() error: vector must not be empty");
        }
        return *std::min_element(vec.begin(), vec.end());
    }


    /**
     * @brief Get a random element from a vector.
     *
     * @param vec A non-empty vector.
     * @return A random element from vec.
     * @throws std::invalid_argument if vec is empty.
     */
    template<typename T>
    T getRandomElement(const std::vector<T>& vec)
    {
        if (vec.empty())
        {
            throw std::invalid_argument("stevensVectorLib::getRandomElement() error: vector must not be empty");
        }
        size_t randomIndex = std::rand() % vec.size();
        return vec[randomIndex];
    }


    /**
     * @brief Concatenate two vectors.
     *
     * @param firstVec The first vector.
     * @param secondVec The second vector to append.
     * @return A new vector containing all elements of firstVec followed by all elements of secondVec.
     */
    template<typename T>
    std::vector<T> concat(const std::vector<T>& firstVec, const std::vector<T>& secondVec)
    {
        std::vector<T> result;
        result.reserve(firstVec.size() + secondVec.size());
        result.insert(result.end(), firstVec.begin(), firstVec.end());
        result.insert(result.end(), secondVec.begin(), secondVec.end());
        return result;
    }


    /**
     * @brief Get elements that are not common between two vectors.
     *
     * @param firstVec First vector.
     * @param secondVec Second vector.
     * @return A vector containing elements in firstVec not in secondVec, and elements in secondVec not in firstVec.
     */
    template<typename T>
    std::vector<T> getUncommonElements(const std::vector<T>& firstVec, const std::vector<T>& secondVec)
    {
        std::vector<T> result;
        result.reserve(firstVec.size() + secondVec.size());

        for (const auto& element : firstVec)
        {
            if (!contains(secondVec, element))
            {
                result.push_back(element);
            }
        }

        for (const auto& element : secondVec)
        {
            if (!contains(firstVec, element))
            {
                result.push_back(element);
            }
        }

        return result;
    }


    /**
     * @brief Helper function to find the maximum element based on a size function.
     *
     * @tparam T The element type.
     * @tparam SizeFunc A callable that returns the size of an element.
     * @param vec The vector to search.
     * @param sizeFunc A function that returns the size of an element.
     * @param searchFromBeginning If true, search from beginning; otherwise from end.
     * @return The element with maximum size.
     * @throws std::invalid_argument if vec is empty.
     */
    template<typename T, typename SizeFunc>
    T findLargestElement(const std::vector<T>& vec, SizeFunc sizeFunc, bool searchFromBeginning = true)
    {
        if (vec.empty())
        {
            throw std::invalid_argument("stevensVectorLib::findLargestElement() error: vector must not be empty");
        }

        size_t maxIndex = searchFromBeginning ? 0 : vec.size() - 1;
        size_t maxSize = sizeFunc(vec[maxIndex]);

        if (searchFromBeginning)
        {
            for (size_t i = 1; i < vec.size(); ++i)
            {
                size_t currentSize = sizeFunc(vec[i]);
                if (currentSize > maxSize)
                {
                    maxSize = currentSize;
                    maxIndex = i;
                }
            }
        }
        else
        {
            for (size_t i = vec.size() - 1; i-- > 0; )
            {
                size_t currentSize = sizeFunc(vec[i]);
                if (currentSize > maxSize)
                {
                    maxSize = currentSize;
                    maxIndex = i;
                }
            }
        }

        return vec[maxIndex];
    }


    /**
     * @brief Find the vector with the greatest size from a 2D vector.
     *
     * @param vecOfVecs A 2D vector to search.
     * @param searchFrom "beginning" to search from start, "end" to search from end.
     * @return The vector with the greatest size.
     * @throws std::invalid_argument if vecOfVecs is empty.
     */
    template<typename T>
    std::vector<T> getLargestVectorElement(const std::vector<std::vector<T>>& vecOfVecs,
                                           const std::string& searchFrom = "beginning")
    {
        return findLargestElement(vecOfVecs,
                                  [](const std::vector<T>& v) { return v.size(); },
                                  searchFrom == "beginning");
    }


    /**
     * @brief Find the longest string element in a vector.
     *
     * @param vec A vector of string-like objects.
     * @param searchFrom "beginning" to search from start, "end" to search from end.
     * @return The string with the greatest length.
     * @throws std::invalid_argument if vec is empty.
     */
    template<typename T>
    T getLongestStringElement(const std::vector<T>& vec, const std::string& searchFrom = "beginning")
    {
        return findLargestElement(vec,
                                  [](const T& s) { return s.length(); },
                                  searchFrom == "beginning");
    }


    /**
     * @brief Reorient a 2D vector by transposing rows and columns.
     *
     * Example:
     *   input  = {{"Name", "Age"}, {"Alice", "30"}, {"Bob", "25"}}
     *   output = {{"Name", "Alice", "Bob"}, {"Age", "30", "25"}}
     *
     * @param inputVecOfVecs A 2D vector to reorient.
     * @return The transposed 2D vector.
     */
    template<typename T>
    std::vector<std::vector<T>> reorient2DVector(const std::vector<std::vector<T>>& inputVecOfVecs)
    {
        if (inputVecOfVecs.empty())
        {
            return {};
        }

        size_t maxCols = getLargestVectorElement(inputVecOfVecs).size();
        std::vector<std::vector<T>> outputVecOfVecs(maxCols);

        for (const auto& row : inputVecOfVecs)
        {
            for (size_t col = 0; col < row.size(); ++col)
            {
                outputVecOfVecs[col].push_back(row[col]);
            }
        }

        return outputVecOfVecs;
    }


    /**
     * @brief Remove duplicate elements from a vector, preserving order.
     *
     * Example: {1, 2, 1, 3, 4, 4, 5, 1} becomes {1, 2, 3, 4, 5}
     *
     * @param vec The vector to process.
     * @return A new vector with duplicates removed.
     */
    template<typename T>
    std::vector<T> eraseDuplicateElements(const std::vector<T>& vec)
    {
        std::unordered_set<T> seen;
        std::vector<T> result;
        result.reserve(vec.size());

        for (const auto& element : vec)
        {
            if (seen.insert(element).second)
            {
                result.push_back(element);
            }
        }

        return result;
    }


    /**
     * @brief Compute the difference between two vectors.
     *
     * Removes elements from firstVec that appear in secondVec (one occurrence per match).
     *
     * Example: firstVec = {1, 1, 2, 3, 4, 5}, secondVec = {1, 3, 5}
     *          result = {1, 2, 4}
     *
     * @param firstVec The vector to subtract from.
     * @param secondVec The vector containing elements to remove.
     * @return A new vector with the difference.
     */
    template<typename T>
    std::vector<T> difference(const std::vector<T>& firstVec, const std::vector<T>& secondVec)
    {
        std::vector<T> result = firstVec;

        for (const auto& element : secondVec)
        {
            auto it = std::find(result.begin(), result.end(), element);
            if (it != result.end())
            {
                result.erase(it);
            }
        }

        return result;
    }


    /**
     * @brief Remove and return the first element of a vector.
     *
     * @param vec The vector to pop from (modified in place).
     * @return The first element of vec.
     * @throws std::invalid_argument if vec is empty.
     */
    template<typename T>
    T popFront(std::vector<T>& vec)
    {
        if (vec.empty())
        {
            throw std::invalid_argument("stevensVectorLib::popFront() error: vector must not be empty");
        }

        T firstElement = std::move(vec.front());
        vec.erase(vec.begin());
        return firstElement;
    }

} // namespace stevensVectorLib

#endif // STEVENS_VECTOR_LIB_HPP

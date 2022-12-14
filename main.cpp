//
//  main.cpp
//  CentralPolygonNumbers
//
//  Created by Pranav Saravanan.
//

#include <iostream>
#include <fstream>

class CentralPolygonNumbers
{
  private:
    int *mp_iNumbers;   // Pointer to an array of integers
    int m_nMax;         // Maximum number of entries in the sequence

  public:
    // Default constructor
    CentralPolygonNumbers()
    {
      m_nMax = 0;
      mp_iNumbers = new int[1];
      mp_iNumbers[0] = 1;
    }

    // Overloaded constructor
    CentralPolygonNumbers(int nMax)
    {
      m_nMax = nMax;
      mp_iNumbers = new int[nMax + 1];

      // Calculate the first N entries in the Central Polygon Numbers sequence
      for (int n = 0; n <= nMax; n++)
      {
        mp_iNumbers[n] = (n * n + n + 2) / 2;
      }
    }

    // Class destructor
    ~CentralPolygonNumbers()
    {
      // Deallocate the memory used for the sequence
      delete[] mp_iNumbers;
      std::cout << "Memory deallocated, ~CentralPolygonNumbersCalled" << std::endl;
    }

    // Public member function to display the sequence
    void displaySequence()
    {
      for (int n = 0; n <= m_nMax; n++)
      {
        std::cout << "n: " << n << ", maximum number of pieces: " << mp_iNumbers[n] << " " << std::endl;
      }
      std::cout << std::endl;
    }

    // Public member function to save the sequence to a file
    void saveSequence(std::string filename)
    {
      // Open the output file stream
      std::ofstream outFile;
      outFile.open("centralpolygon.txt");

      // Save the sequence to the file
      for (int n = 0; n <= m_nMax; n++)
      {
        outFile << mp_iNumbers[n] << " ";
      }
      outFile << std::endl;

      // Close the file
      outFile.close();
    }
};

int main()
{
  // Create a CentralPolygonNumbers object with the maximum value of n set to 10
  CentralPolygonNumbers sequence(10);

  // Display the sequence to standard output
  sequence.displaySequence();

  // Save the sequence to a file
  sequence.saveSequence("centralpolygon.txt");

  return 0;
}

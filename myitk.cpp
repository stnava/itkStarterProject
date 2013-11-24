#include <cmath>
#include <iostream>
#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkNiftiImageIOFactory.h"
#include "itkImageIOFactory.h"
#include "itkImageFileReader.h"
#include "itkImage.h"

int main( int argc, char *argv[]  )
{
  itk::NiftiImageIOFactory::RegisterOneFactory();     
  typedef itk::Image< float , 2 > ImageType ;
  std::string fn = std::string( argv[1] );
  if ( fn.length() < 3 ) 
    {
    std::cout << "Usage: " << std::endl;
    std::cout << argv[0] << " filename.nii.gz " << std::endl;
    return EXIT_FAILURE;
    }
  itk::ImageIOBase::Pointer iobase = 
      itk::ImageIOFactory::CreateImageIO( fn.c_str() , itk::ImageIOFactory::ReadMode );
  if ( iobase.IsNull() )
    {
    std::cout << "iobase is null" << std::endl ;
    }
  else
    {
    std::cout << "iobase is ok " << std::endl ;
    iobase->SetFileName( fn.c_str() );
    iobase->ReadImageInformation( );
    std::cout << "iobase is done " << std::endl ;
    }
  return 0;
}


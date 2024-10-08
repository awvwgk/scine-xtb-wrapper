/**
 * @file
 * @copyright This code is licensed under the 3-clause BSD license.\n
 *            Copyright ETH Zurich, Laboratory of Physical Chemistry, Reiher Group.\n
 *            See LICENSE.txt for details.
 */
#ifndef XTB_GFNFFWRAPPER_H_
#define XTB_GFNFFWRAPPER_H_

/* Internal Includes */
#include "Xtb/Wrapper/XtbCalculatorBase.h"
/* External Includes*/
#include <Utils/CalculatorBasics.h>
#include <Utils/Technical/CloneInterface.h>
#include <mutex>

namespace Scine {
namespace Xtb {

/**
 * @brief The SCINE Calculator for molecular GFNFF Calculations.
 */
class GFNFFWrapper : public Scine::Utils::CloneInterface<GFNFFWrapper, XtbCalculatorBase> {
 public:
  static constexpr const char* model = "GFNFF";
  static constexpr const char* program = "Xtb";
  /// @brief Default Constructor
  GFNFFWrapper() = default;
  /// @brief Default Destructor.
  ~GFNFFWrapper() = default;
  /// @brief Copy Constructor.
  GFNFFWrapper(const GFNFFWrapper& other) = default;
  /**
   * @brief Getter for the name of the underlying method.
   * @returns Returns the name of the underlying method.
   */
  std::string name() const final {
    return "XtbGFNFFCalculator";
  };
  /**
   * @brief Report the possible properties.
   * @return Scine::Utils::PropertyList
   */
  Scine::Utils::PropertyList possibleProperties() const final {
    return Scine::Utils::Property::Energy | Scine::Utils::Property::Gradients | Scine::Utils::Property::Hessian |
           Scine::Utils::Property::Thermochemistry;
  };
  /**
   * @brief Check if the method family is supported by this calculator.
   * @param methodFamily The method family as all caps string.
   * @return true  If it is supported.
   * @return false If it is not supported.
   */
  bool supportsMethodFamily(const std::string& methodFamily) const final {
    return methodFamily == "GFNFF";
  }
  /**
   * @brief Run the calculation.
   * @param dummy
   * @return const Scine::Utils::Results& The results.
   */
  virtual const Scine::Utils::Results& calculate(std::string dummy) final;

 private:
  static std::mutex _mtx;
};

} /* namespace Xtb */
} /* namespace Scine */

#endif /* XTB_GFNFFWRAPPER_H_ */

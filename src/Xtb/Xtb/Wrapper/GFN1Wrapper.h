/**
 * @file
 * @copyright This code is licensed under the 3-clause BSD license.\n
 *            Copyright ETH Zurich, Laboratory of Physical Chemistry, Reiher Group.\n
 *            See LICENSE.txt for details.
 */
#ifndef XTB_GFN1WRAPPER_H_
#define XTB_GFN1WRAPPER_H_

/* Internal Includes */
#include "Xtb/Wrapper/XtbCalculatorBase.h"
/* External Includes*/
#include <Utils/CalculatorBasics.h>
#include <Utils/Technical/CloneInterface.h>
#include <mutex>

namespace Scine {
namespace Xtb {

/**
 * @brief The SCINE Calculator for molecular GFN1 Calculations.
 */
class GFN1Wrapper : public Scine::Utils::CloneInterface<GFN1Wrapper, XtbCalculatorBase, Scine::Core::Calculator> {
 public:
  static constexpr const char* model = "GFN1";
  static constexpr const char* program = "Xtb";
  /// @brief Default Constructor
  GFN1Wrapper();
  /// @brief Default Destructor.
  ~GFN1Wrapper() = default;
  /// @brief Copy Constructor.
  GFN1Wrapper(const GFN1Wrapper& other) = default;
  /**
   * @brief Getter for the name of the underlying method.
   * @returns Returns the name of the underlying method.
   */
  std::string method() const final {
    return GFN1Wrapper::model;
  };
  /**
   * @brief Getter for the name of the underlying calculator.
   * @returns Returns the name of the underlying calculator.
   */
  std::string name() const final {
    return "XtbGFN1Calculator";
  };
  /**
   * @brief Report the possible properties.
   * @return Scine::Utils::PropertyList
   */
  Scine::Utils::PropertyList possibleProperties() const final {
    return Utils::Property::Energy | Utils::Property::AtomicCharges | Utils::Property::Gradients | Utils::Property::Hessian |
           Utils::Property::BondOrderMatrix | Utils::Property::SuccessfulCalculation | Utils::Property::Thermochemistry;
  };
  /**
   * @brief Check if the method family is supported by this calculator.
   * @param methodFamily The method family as all caps string.
   * @return true  If it is supported.
   * @return false If it is not supported.
   */
  bool supportsMethodFamily(const std::string& methodFamily) const final {
    return methodFamily == "GFN1";
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

#endif /* XTB_GFN1WRAPPER_H_ */

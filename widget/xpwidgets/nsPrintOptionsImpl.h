/* -*- Mode: IDL; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef nsPrintOptionsImpl_h__
#define nsPrintOptionsImpl_h__

#include "nsCOMPtr.h"
#include "nsIPrintOptions.h"
#include "nsIPrintSettingsService.h"
#include "nsString.h"
#include "nsFont.h"

/**
 *   Class nsPrintOptions
 */
class nsPrintOptions : public nsIPrintOptions,
                       public nsIPrintSettingsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTOPTIONS
  NS_DECL_NSIPRINTSETTINGSSERVICE

  /**
   * method Init
   *  Initializes member variables. Every consumer that does manual
   *  creation (instead of do_CreateInstance) needs to call this method
   *  immediately after instantiation.
   */
  virtual nsresult Init();

  nsPrintOptions();

protected:
  virtual ~nsPrintOptions();

  void ReadBitFieldPref(const char * aPrefId, int32_t anOption);
  void WriteBitFieldPref(const char * aPrefId, int32_t anOption);
  void ReadJustification(const char * aPrefId, int16_t& aJust,
                         int16_t aInitValue);
  void WriteJustification(const char * aPrefId, int16_t aJust);
  void ReadInchesToTwipsPref(const char * aPrefId, int32_t&  aTwips,
                             const char * aMarginPref);
  void WriteInchesFromTwipsPref(const char * aPrefId, int32_t aTwips);
  void ReadInchesIntToTwipsPref(const char * aPrefId, int32_t&  aTwips,
                                const char * aMarginPref);
  void WriteInchesIntFromTwipsPref(const char * aPrefId, int32_t aTwips);

  nsresult ReadPrefDouble(const char * aPrefId, double& aVal);
  nsresult WritePrefDouble(const char * aPrefId, double aVal);

  /**
   * method ReadPrefs
   * @param aPS          a pointer to the printer settings
   * @param aPrinterName the name of the printer for which to read prefs
   * @param aFlags       flag specifying which prefs to read
   */
  virtual nsresult ReadPrefs(nsIPrintSettings* aPS, const nsAString&
                             aPrinterName, uint32_t aFlags);
  /**
   * method WritePrefs
   * @param aPS          a pointer to the printer settings
   * @param aPrinterName the name of the printer for which to write prefs
   * @param aFlags       flag specifying which prefs to read
   */
  virtual nsresult WritePrefs(nsIPrintSettings* aPS, const nsAString& aPrefName,
                              uint32_t aFlags);
  const char* GetPrefName(const char *     aPrefName,
                          const nsAString&  aPrinterName);

  /**
   * method _CreatePrintSettings
   *   May be implemented by the platform-specific derived class
   *
   * @return             printer settings instance
   */
  virtual nsresult _CreatePrintSettings(nsIPrintSettings **_retval);

  // Members
  nsCOMPtr<nsIPrintSettings> mGlobalPrintSettings;

  nsCString mPrefName;

private:
  // These are not supported and are not implemented!
  nsPrintOptions(const nsPrintOptions& x);
  nsPrintOptions& operator=(const nsPrintOptions& x);
};

#endif /* nsPrintOptionsImpl_h__ */
